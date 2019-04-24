AUTOMAKE_OPTIONS = subdir-objects 

# Configuracao do binario de tests
# Este binario ira agrupar todos os testes unitarios
TESTS = lexer
check_PROGRAMS = lexer

lexer_SOURCES = lexer.c\
								$(top_builddir)/src/lexer.c

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

lexer_CFLAGS = -I/usr/include \
							 -I$(includedir)
lexer_LDADD = ${LEXER_LIBS} -lcheck

