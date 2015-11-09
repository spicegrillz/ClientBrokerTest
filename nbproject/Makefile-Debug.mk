#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/BrokerHandler.o \
	${OBJECTDIR}/ClientStorage.o \
	${OBJECTDIR}/ClientTestSuite.o


# C Compiler Flags
CFLAGS=`cppunit-config --cflags` 

# CC Compiler Flags
CCFLAGS=-std=c++11
CXXFLAGS=-std=c++11

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lgtest -lpthread `cppunit-config --libs`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk cl_test

cl_test: ${OBJECTFILES}
	${LINK.cc} -o cl_test ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/BrokerHandler.o: BrokerHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -IGTEST_ROOT/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BrokerHandler.o BrokerHandler.cpp

${OBJECTDIR}/ClientStorage.o: ClientStorage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -IGTEST_ROOT/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ClientStorage.o ClientStorage.cpp

${OBJECTDIR}/ClientTestSuite.o: ClientTestSuite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -IGTEST_ROOT/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ClientTestSuite.o ClientTestSuite.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} cl_test

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
