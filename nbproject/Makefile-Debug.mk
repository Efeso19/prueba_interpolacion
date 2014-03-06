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
	${OBJECTDIR}/Clases/Game.o \
	${OBJECTDIR}/Clases/PhysicsState.o \
	${OBJECTDIR}/Clases/Player.o \
	${OBJECTDIR}/Clases/Render.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/SFML/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/prueba_interpolacion

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/prueba_interpolacion: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/prueba_interpolacion ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Clases/Game.o: Clases/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/Clases
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/SFML/include -IIncludes -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Clases/Game.o Clases/Game.cpp

${OBJECTDIR}/Clases/PhysicsState.o: Clases/PhysicsState.cpp 
	${MKDIR} -p ${OBJECTDIR}/Clases
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/SFML/include -IIncludes -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Clases/PhysicsState.o Clases/PhysicsState.cpp

${OBJECTDIR}/Clases/Player.o: Clases/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/Clases
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/SFML/include -IIncludes -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Clases/Player.o Clases/Player.cpp

${OBJECTDIR}/Clases/Render.o: Clases/Render.cpp 
	${MKDIR} -p ${OBJECTDIR}/Clases
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/SFML/include -IIncludes -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Clases/Render.o Clases/Render.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/SFML/include -IIncludes -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/prueba_interpolacion

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
