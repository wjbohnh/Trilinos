

#
# A) Define the package
#

TRIBITS_PACKAGE(Claps)

#
# B) Set up package-specific options
#

TRIBITS_ADD_OPTION_AND_DEFINE(${PACKAGE_NAME}_ENABLE_SClaps
  HAVE_SCLAPS
  "Enable Sandia Claps interface."
  OFF )

#
# C) Add the libraries, tests, and examples
#

ADD_SUBDIRECTORY(src)

TRIBITS_ADD_TEST_DIRECTORIES(test)

#TRIBITS_ADD_EXAMPLE_DIRECTORIES(example)

#
# D) Do standard postprocessing
#

TRIBITS_PACKAGE_POSTPROCESS()
