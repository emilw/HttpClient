C:\Chocolatey\bin\cmake.bat "Visual Studio 11 2012" ..
Import-Module -Name ".\build_stuff\WindowsAdditions\Invoke-MsBuild.psm1"

Write-Host("Starting build")
$buildSucceeded = Invoke-MsBuild -Path ".\HttpClient.sln"

if ($buildSucceeded)
{ Write-Host "Build completed successfully." }
else
{ Write-Host "Build failed. Check the build log file for errors." }