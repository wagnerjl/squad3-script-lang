AUTOMAKE_OPTIONS = subdir-objects 

# Configuracao do binario de tests
# Este binario ira agrupar todos os testes unitarios
TESTS = tests
check_PROGRAMS = tests
tests_SOURCES = main.c

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

tests_CPPFLAGS = \
	-I/usr/include \
	-I$(includedir) \
	-I$(top_builddir)/src

