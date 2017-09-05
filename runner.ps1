

Write-Output 'Running GeoRegistrationAnalyzer Build Utility.'
$CMAKE_ARGLIST=""

# Check if Build-Options subscript exists
if( Test-Path ./runner-options.ps1 )
{
    Write-Output ' -> Importing Build Options'
    . .\runner-options.ps1
	$CMAKE_ARGLIST=Update_CMake_Args
    Update_Env_Vars
}
else
{
    Write-Output ' -> Skipping Import of Runner Options'
}


#   Enter release directory
if( -Not $(Test-Path ./release) )
{
    New-Item -ItemType Directory release
}

Set-Location release

$CMD_ARGS="cmake $CMAKE_ARGLIST .."
Invoke-Expression $CMD_ARGS 

Set-Location ..