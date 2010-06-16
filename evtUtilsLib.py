#$Id: evtUtilsLib.py,v 1.2 2008/02/26 03:10:49 glastrm Exp $
def generate(env, **kw):
    if not kw.get('depsOnly',0):
        env.Tool('addLibrary', library = ['evtUtils'])
    env.Tool('facilitiesLib')
    env.Tool('xmlBaseLib')

def exists(env):
    return 1
