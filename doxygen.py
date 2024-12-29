## @file doxygen.py
## Extra-script for automaticly build the documentation using doxygen
## @author d.macsddau
## @copyright \@2024, d.macsddau
## @version 0.01
import subprocess

Import ("env")

def make_documentation(source, target, env):
    process = subprocess.run('doxygen Doxyfile', shell=True)

env.AddPostAction("$PROGPATH", make_documentation)
