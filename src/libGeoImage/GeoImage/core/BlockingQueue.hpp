/**
 * @file    BlockingQueue.hpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#ifndef LIB_GEO_IMAGE_CORE_BLOCKING_QUEUE_HPP
#define LIB_GEO_IMAGE_CORE_BLOCKING_QUEUE_HPP

// C++ Libraries
#include <mutex>
#include <queue>
#include <condition_variable>


namespace GEO {

/**
 * @class Blocking_Queue
 *
 * @brief Simple thread-safe class for blocking push/pop operations.
 *
 * General usage guidelines
 *
 * - Construct
 * - Call Start()
 * -
 *
 */
template<class T>
class Blocking_Queue {

    public:

        /**
         * @brief Default Constructor
         */
        Blocking_Queue()
                : m_break(false),
                  m_complete(false) {
        }


        /**
         * @brief Clear the Queue
         */
        void Clear() {
            // Release all waiting queue pops
            {
                std::unique_lock<std::mutex> lock{m_mutex};
                m_break = true;
                m_complete = false;
                m_cv.notify_all();
            }

            // Clean up
            {
                std::unique_lock<std::mutex> lock{m_mutex};
                std::queue<T> empty;
                std::swap(m_queue, empty);
                m_break = false;
                m_complete = false;
            }
        }


        /**
         * @brief Get the Size of the queue.
         * @return
         */
        size_t Size() {
            // Lock the method
            std::unique_lock<std::mutex> lock{m_mutex};

            return m_queue.size();
        }


        /**
         * @brief Push Value onto Queue
         *
         * @return True if successful, false if not initialized or full.
         */
        bool Push(T &&value) {
            std::unique_lock<std::mutex> lock{m_mutex};
            if (m_break || m_complete) {
                return false;
            } else {
                m_queue.push(value);
                m_cv.notify_one();
                return true;
            }
        }


        /**
         * @brief Push value onto queue.
         */
        bool Push(const T &value) 
        {
            std::unique_lock<std::mutex> lock{m_mutex};
            if (m_break || m_complete) {
                return false;
            } else {
                m_queue.push(value);
                m_cv.notify_one();
                return true;
            }
        }


        /**
         * @brief Try a pop
         *
         * @param value
         * @return
         */
        bool Try_Pop(T &value) {
            std::unique_lock<std::mutex> lock{m_mutex};

            if (m_break) {
                return false;
            } else if (m_queue.empty()) {
                return false;
            } else {
                value = m_queue.front();
                m_queue.pop();
                return true;
            }
        }


        /**
         * @brief Pop data from queue
         * @param value
         * @return
         */
        bool Pop(T &value) 
        {
            std::unique_lock<std::mutex> lock{m_mutex};
            m_cv.wait(lock, [this] {
                if (m_complete) return true;
                else if (m_break) return true;
                else return (!m_queue.empty());
            });

            if (m_break) {
                return false;
            } else if (m_complete && m_queue.empty()) {
                return false;
            } else {
                value = m_queue.front();
                m_queue.pop();
                return true;
            }
        }


        /**
         * @brief Start or Initialize the Blocking Queue
         */
        void Start() {
            Validate();
        }


        /**
         * @brief Complete actions on the queue
         */
        void Complete() {
            std::unique_lock<std::mutex> lock{m_mutex};
            m_complete = true;
            m_cv.notify_all();

        }


        /**
         * @brief Invalidate the Queue, causing
         */
        void Invalidate() {
            std::unique_lock<std::mutex> lock{m_mutex};
            m_break = true;
            m_complete = false;
            m_cv.notify_all();

        }

        /**
         * @brief Validate data on the queue / Re-Initialize
         */
        void Validate() {
            std::unique_lock<std::mutex> lock{m_mutex};
            m_break = false;
            m_complete = false;
        }


        /**
         * @brief Check if working / valid.
         * @return
         */
        bool Is_Valid() {
            std::unique_lock<std::mutex> lock{m_mutex};
            if (m_break) return false;
            if (m_complete) return false;
            else return true;
        }


        /**
         *
         * @return
         */
        bool Is_Complete() const {
            return m_complete;
        }


        /**
         * @brief
         */
        bool Is_Invalid() const {
            return m_break;
        }

    private:


        std::mutex m_mutex;
        std::condition_variable m_cv;
        bool m_break;
        bool m_complete;
        std::queue<T> m_queue;

};

} // End of GEO Namespace

#endif
