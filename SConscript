# -*- python -*-
# $Id: SConscript,v 1.28 2015/02/03 14:37:15 bregeon Exp $
# Authors: Eric Charles <echarles@slac.stanford.edu>
# Version: evtUtils-00-03-01
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('evtUtilsLib', depsOnly = 1)

evtUtilsLib = libEnv.SharedLibrary('evtUtils', listFiles(['src/*.cxx']))
progEnv.Tool('evtUtilsLib')

evtUtilsApp_MakeEventClass = progEnv.Program('MakeEventClass', ['apps/MakeEventClass.cxx'])
evtUtilsApp_MakeEventClassPyDict = progEnv.Program('MakeEventClassPyDict', ['apps/MakeEventClassPyDict.cxx'])
evtUtilsApp_MakeEventClassHtml = progEnv.Program('MakeEventClassHtml', ['apps/MakeEventClassHtml.cxx'])

progEnv.Tool('registerTargets',
             package = 'evtUtils',
             libraryCxts = [[evtUtilsLib, libEnv]],
             xml = listFiles(['xml/*.xml']),
             testAppCxts = [[evtUtilsApp_MakeEventClass,evtUtilsApp_MakeEventClassPyDict,evtUtilsApp_MakeEventClassHtml,progEnv]],
             includes = listFiles(['evtUtils/*.h']))
