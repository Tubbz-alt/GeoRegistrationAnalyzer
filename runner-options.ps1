
function Add_CMake_Var( [string]$Key, [string]$Value )
{
	Write-Output  "-D${Key}=${Value}"
}

function Append_CMake_Var( [string]$Key, [string]$Value )
{
	Write-Output " $(Add_CMake_Var $Key $Value)"
}

#  Print the Boost-Root
function Update_CMake_Args()
{
	$CMAKE_ARGLIST=""
	$CMAKE_ARGLIST += $(Append_CMake_Var "BOOST_ROOT" "D:/opt/msvc-2017")
	
	Write-Output $CMAKE_ARGLIST
}

function Update_Env_Vars()
{
	$env:GDAL_ROOT="D:/opt/msvc-2017"
}