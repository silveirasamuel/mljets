# PYTHIA configuration file.
# Generated on qua mar 18 16:38:20 -03 2020 with the user supplied options:
# --enable-debug
# --enable-shared
# --enable-64bit
# --with-root=/home/sspsilveira/ROOT/root-build
# --with-fastjet3=/home/sspsilveira/Fastjet/fastjet-3.3.3

# Install directory prefixes.
PREFIX_BIN=/home/sspsilveira/pythia8244/bin
PREFIX_INCLUDE=/home/sspsilveira/pythia8244/include
PREFIX_LIB=/home/sspsilveira/pythia8244/lib
PREFIX_SHARE=/home/sspsilveira/pythia8244/share/Pythia8

# Compilation flags (see ./configure --help for further documentation).
ENABLE_SHARED=true
CXX=g++
CXX_COMMON=-g -m64  -pedantic -W -Wall -Wshadow -fPIC
CXX_SHARED=-shared
CXX_SONAME=-Wl,-soname,
LIB_SUFFIX=.so

# EVTGEN configuration.
EVTGEN_USE=false
EVTGEN_BIN=
EVTGEN_INCLUDE=
EVTGEN_LIB=

# FASTJET3 configuration.
FASTJET3_USE=true
FASTJET3_BIN=/home/sspsilveira/Fastjet/fastjet-3.3.3/bin
FASTJET3_INCLUDE=/home/sspsilveira/Fastjet/fastjet-3.3.3/include
FASTJET3_LIB=/home/sspsilveira/Fastjet/fastjet-3.3.3/lib

# HEPMC2 configuration.
HEPMC2_USE=false
HEPMC2_BIN=
HEPMC2_INCLUDE=
HEPMC2_LIB=

# HEPMC3 configuration.
HEPMC3_USE=false
HEPMC3_BIN=
HEPMC3_INCLUDE=
HEPMC3_LIB=

# LHAPDF5 configuration.
LHAPDF5_USE=false
LHAPDF5_BIN=
LHAPDF5_INCLUDE=
LHAPDF5_LIB=

# LHAPDF6 configuration.
LHAPDF6_USE=false
LHAPDF6_BIN=
LHAPDF6_INCLUDE=
LHAPDF6_LIB=

# POWHEG configuration.
POWHEG_USE=false
POWHEG_BIN=
POWHEG_INCLUDE=
POWHEG_LIB=

# PROMC configuration.
PROMC_USE=false
PROMC_BIN=
PROMC_INCLUDE=
PROMC_LIB=

# ROOT configuration.
ROOT_USE=true
ROOT_BIN=/home/sspsilveira/ROOT/root-build/bin/
ROOT_LIBS=-L/home/sspsilveira/ROOT/root-build/lib -lGui -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lROOTDataFrame -pthread -lm -ldl -rdynamic
CXX_ROOT=-g -m64  -W -Wall -Wshadow -fPIC -pthread -std=c++11 -m64 -I/home/sspsilveira/ROOT/root-build/include

# GZIP configuration.
GZIP_USE=false
GZIP_BIN=
GZIP_INCLUDE=
GZIP_LIB=

# BOOST configuration.
BOOST_USE=false
BOOST_BIN=
BOOST_INCLUDE=
BOOST_LIB=

# PYTHON configuration.
PYTHON_USE=false
PYTHON_BIN=
PYTHON_INCLUDE=
PYTHON_LIB=
