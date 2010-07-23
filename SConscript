# -*- python -*-
# $Id: SConscript,v 1.15 2010/07/09 20:59:29 echarles Exp $
# Authors: Eric Charles <echarles@slac.stanford.edu>
# Version: evtUtils-00-01-07
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('evtUtilsLib', depsOnly = 1)

evtUtilsLib = libEnv.SharedLibrary('evtUtils', listFiles(['src/*.cxx']))
progEnv.Tool('evtUtilsLib')

evtUtilsApp_MakeEventClass = progEnv.Program('MakeEventClass', ['apps/MakeEventClass.cxx'])
evtUtilsApp_MakeEventClassHtml = progEnv.Program('MakeEventClassHtml', ['apps/MakeEventClassHtml.cxx'])

progEnv.Tool('registerTargets',
             package = 'evtUtils',
             libraryCxts = [[evtUtilsLib, libEnv]],
             testAppsCxts = [evtUtilsApp_MakeEventClass,progEnv],
             includes = listFiles(['evtUtils/*.h']))
