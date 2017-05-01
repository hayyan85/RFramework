<small>
© 2012 RealTick LLC All rights reserved.

<em>Use of the RealTick API®, including, but not limited to, all code and
documentation, is subject to the RealTick API® terms and conditions which are
posted on www.realtick.com.  The code contained herein is deemed to be part of
the "Licensed Product" as referred to in the end user license agreements
between the user and RealTick.</em>
</small>

<hr />
# Introduction

This document describes the requirements for compiling applications with the RealTick C++ API.  There is a separate section for each platform.

For information about coding API applications, please see the document <b>ApiProgrammingGuide ("Programming with the RealTick API for C+").</b>

<hr />
# Compiling RealTickApi Applications (Windows)

<hr />
## Running on Windows

A pre-compiled copy of the QuickStart application is installed into your Start Menu (RealTick) by the installer, and all configuration will be in place.  Simply run the application and enter your credentials.

<hr />
## API Components in Windows

The Windows version of the RealTickApi includes:

- In the C:\RealTick folder:
 - QuickStart32.exe (pre-compiled version of the QuickStart)
 - RealTickApi32.dll (API implementation DLL file)
- In the C:\RealTick\API\include folder:
 - RealTickApi.h (API header file)
 - FIDS.H (API field definition file)
- In the C:\RealTick\API\lib folder:
 - RealTickApi32.lib (API linker lib file)
- In the C:\RealTick\API\SampleCode folder:
 - source files for the QuickStart application
- In the C:\RealTick\Documentation folder:
 - CompilingRealTickApiApplications (this file)
 - ApiProgrammingGuide (overview of the C++ API)
 - ApiOrderEntry (information about order data)
 - RealTick Api User Guide (information about market data)


<hr />
## Compiling QuickStart for Windows

The QuickStart application can be compiled using the C++ compiler of your choice.  You should set up your project or makefile so that:

- The C:\RealTick\API\include folder is on your INCLUDE path
- The C:\RealTick\API\lib folder is on your LIB path
- You include RealTickApi32.lib in your link library list
- The supplied C++ files are all included in the build

If using Visual Studio, you can begin with a standard Win32 console application project and then adjust to meet these requirements.  Be sure to delete the pre-generated file with the main() method, as the file QuickStart.cpp includes an appropriate main method.



<hr />
## Distributing Applications for Windows

The RealTickApi32 DLL has internal linkages to several other DLLs in the C:\RealTick folder, and these depend in turn on multiple configuration files and registry keys.  Therefore it is only possible to deploy an API application on a machine where either the RealTickApi or RealTick itself has already been installed.

When deploying to a machine where RealTick has been installed, but not the RealTickApi, you should ensure that the file RealTickApi32.dll is installed into the C:\RealTick folder.

Your own application can be deployed into the C:\RealTick folder as well.  If it is deployed to another folder, then the C:\RealTick folder must be on the system PATH to ensure that DLL references can be resolved.



<hr />
# Compiling RealTickApi Applications (Linux)
<hr />

## Running on Linux

A pre-compiled copy of the QuickStart application is installed into the ./SampleCode/QuickStart folder.

In order to run this code, you will need to have several libraries (listed below) installed.  QuickStart will give you a load error if it cannot find any particular library.

You will also need to provide some configuration:

1.  Environment variables to locate the API components and configuration file
2.  Configuration file contents

### Required Libraries

 - gcc v4.6.3
 - libtbb
 - boost v1.0.48.0
 - boost-lib
 - libxml++ v2.6
 - libcurl


### Environment Variables

The required environment variables are:
<pre>
export RTIX_PROFILE=/home/userID/RealTickApi
export LD_LIBRARY_PATH=/usr/local/lib:/home/userID/RealTickApi/lib
export RTIX_ROOT=/home/userID/RealTickApi
</pre>

(Assuming that the API is installed in to your ~/RealTickApi folder and 'userID' is your user name)

 - RTIX\_PROFILE indicates the directory where the rtix.conf file is located. 
 - LD\_LIBRARY\_PATH indicates a list of additional directories where the loader looks for shared libraries.
 - RTIX\_ROOT indicates the location of a global rtix.conf file.

### Configuration File

The root RealTickApi folder contains a file called rtix.conf.example.  Copy this folder to rtix.conf and edit it with your user-specific configuration settings.  The required settings are:

 - UserName
 - Domain
 - Password

The remaining settings are optional and only need to be set if specified by API Support for your account.

Updated and/or platform-specific build notes and dependencies can be found in the ReadMe.txt file bundled with each RealTickApi release.


<hr />
## API Components for Linux
The Linux version of the RealTickApi includes:

- In the ./include folder:
 - RealTickApi.h (API header file)
 - FIDS.H (API field definition file)
- In the ./lib folder:
 - libRealTickApi.so (API library file)
 - additional dependent library files
- In the ./SampleCode/QuickStart folder:
 - QuickStart (the compiled sample application)
 - source files for the QuickStart application
- In the ./Documentation folder:
 - CompilingRealTickApiApplications (this file)
 - ApiProgrammingGuide (overview of the C++ API)
 - ApiOrderEntry (information about order data)
 - RealTick Api User Guide (information about market data)


<hr />
## Compiling QuickStart for Linux

In the SampleCode/QuickStart folder, there is a makefile that will build the QuickStart.

Before attempting a build, be sure to rename or move the pre-compiled QuickStart executable that is installed with the API.

The makefile assumes that you have the same libraries installed as listed in the 'Running on Linux' section above.  Be sure that you have installed the development versions (e.g. libcurl-devel / libcur-openss-dev / etc) of these libraries so that the necessary .h and .so files will be present.

Updated and/or platform-specific build notes and dependencies can be found in the ReadMe.txt file bundled with each RealTickApi release.

