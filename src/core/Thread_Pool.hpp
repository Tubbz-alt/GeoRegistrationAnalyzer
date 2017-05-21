/**
 * @file    Thread_Pool.hpp
 * @author  Marvin Smith
 * @date    5/21/2017
 */
#ifndef CORE_THREAD_POOL
#define CORE_THREAD_POOL

// C++ Standard Library
#include <atomic>
#include <condition_variable>
#include <deque>
#include <memory>
#include <mutex>
#include <thread>
#include <semaphore.h>
#include <string>
#include <vector>



/**
 * @class Worker_Thread
 * @brief Base type for a worker thread
 */
class Worker_Thread
{
    
    public:

        /// Pointer Type
        typedef std::shared_ptr<Worker_Thread> ptr_t;

        /**
         * @brief Constructor
         */
        Worker_Thread();


        /**
         * @brief Destructor
         */
        virtual ~Worker_Thread();


        /**
         * @brief Execute the thread
         *
         * @return 0 on success, other value on failure.
        */
        virtual int Execute();
        

        /**
         * @brief Test to see if code is running.
         */
        inline bool Is_Running()const
        {
            return m_is_running;
        }
        

        /**
         * @brief Set the Running Condition
         *
         * @param[in] flag
         */
        inline void Set_Running_Flag( const bool& flag )
        {
            // Set the flag
            m_is_running = flag;
        }


    protected:
        

        /// Running Flag
        std::atomic<bool> m_is_running;

    private:

        /// Class Name
        std::string m_class_name;

}; // End of Worker_Thread Class


/**
 * @class Thread_Pool
 */
class Thread_Pool{

    public:
        
        /// Pointer Type
        typedef std::shared_ptr<Thread_Pool> ptr_t;


        /**
         * @brief Constructor
         *
         * Generates an empty thread pool with the requested number of threads.
         *
         * @param[in] max_threads Maximum number of threads to run inside pool.
        */
        Thread_Pool( const int& max_threads = 2 );

    
        /**
         * @brief Destructor.
         *
         * Destroys all finished threads.  Note that unfinished threads will cause this
         * method to wait.  It is recommended to force all worker threads to finish.
         */
        ~Thread_Pool();


        /**
         * @brief Initialize thread pool.
         *
         * Starts all threads and preps pool to run.
         *
         * @param[out] status Status of initialization.
         */
        void Initialize( bool& status );
       
        
        /**
         * @brief Assign work to the queue
         *
         * @param[in/out] new_worker New job to assign to work queue.
         */
        void Assign_Work( Worker_Thread::ptr_t new_worker );


        /**
         * @brief Destroy the thread pool.
         *
         * @param[out] status Status of the operation.
         */
        void Destroy_Pool( bool& status );

        
        /**
         * @brief Get Remaining Work
         *
         * @return Number of running work threads.
         */
        int Get_Remaining_Work();
        
        /**
         * @brief Check if still running
         *
         * @return True if jobs are running, false otherwise.
         */
        bool Is_Running()const;

        
        /**
         * @brief Get the max number of threads supported.
         *
         * @return max number of threads.
         */
        inline int Get_Max_Queue_Size()const{
            return m_threads.size();
        }


        /**
         * @brief Wait Until the Pool is Empty.
         *
         * @param[out] status if the operation failed.
        */
        void Wait_Until_Pool_Empty( bool& status );

        /**
         * @brief get the number of current running threads in the pool
         *
         * @param[out] number of threads currently running
         */
        int Get_Current_Running_Threads() ;


        /**
         * @brief Get the list of current worker running.
         *
         * @return
         */
        int Get_Current_Work_Items();


    private:


        /**
         * @brief Start the Work queue jobs.
         */
        void  Execute_Thread( );    
        
        
        /// Class Name
        std::string m_class_name;


        /// Pool Size
        int m_pool_size;
        
        
        /// Mutex Lock
        std::mutex  m_mutex;
        
        
        /// Condition 
        std::condition_variable   m_condv;
        
        
        /// Work QUeue
        std::deque<Worker_Thread::ptr_t>  m_queue;
        
        
        /// Thread List
        std::vector<std::thread> m_threads;
        

        /// Thread Pool State
        volatile int m_pool_state;
 

        /// Number of Open Jobs Pushed
        std::atomic<int> m_number_assigned_workers;

        // Number of currently executing threads
        std::atomic<int> m_number_running_threads;

        /// Assigned Work Mutex
        std::mutex m_number_assigned_workers_mutex;

        /// Assigned Work Condition Variable
        std::condition_variable m_number_assigned_workers_cv;


        /**
         * @enum ThreadPoolStatusType
         *
         * @brief Thread Pool Status Flags
         */
        enum class ThreadPoolStatusType : uint8_t{
            POOL_STOPPED = 0 /**< Thread pool has stopped running.*/,
            POOL_STARTED = 1 /**< Thread pool has started running.*/,
        }; // End of ThreadPoolStatusType Enumeration


}; // End of Thread_Pool Class


#endif
