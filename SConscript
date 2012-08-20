# -*- python -*-
# $Id: SConscript,v 1.22 2011/09/27 23:43:56 jchiang Exp $
# Authors: Eric Charles <echarles@slac.stanford.edu>
# Version: evtUtils-00-02-00
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
             testAppsCxts = [evtUtilsApp_MakeEventClass,evtUtilsApp_MakeEventClassPyDict,evtUtilsApp_MakeEventClassHtml,progEnv],
             includes = listFiles(['evtUtils/*.h']))
