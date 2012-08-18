#$Id: evtUtilsLib.py,v 1.2 2010/09/14 16:38:48 heather Exp $
def generate(env, **kw):
    if not kw.get('depsOnly',0):
        env.Tool('addLibrary', library = ['evtUtils'])
        if env['PLATFORM']=='win32' and env.get('CONTAINERNAME','')=='GlastRelease':
	    env.Tool('findPkgPath', package = 'evtUtils') 
    env.Tool('facilitiesLib')
    env.Tool('xmlBaseLib')
    env.Tool('addLibrary', library = env['rootLibs'])
    env.Tool('addLibrary', library = env['rootGuiLibs'])


def exists(env):
    return 1
