# Temporariamente removido por causa do ubuntu:
# https://www.mail-archive.com/debian-bugs-dist@lists.debian.org/msg1232579.html
# https://stackoverflow.com/questions/18839857/deps-po-no-such-file-or-directory-compiler-error
# AUTOMAKE_OPTIONS = subdir-objects 

# Configuracao do binario de tests
# Este binario ira agrupar todos os testes unitarios
TESTS = lexer parser
check_PROGRAMS = lexer parser

lexer_SOURCES = lexer.c

parser_SOURCES = parser.c

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

lexer_CFLAGS = -I/usr/include \
							 -I$(includedir)

lexer_LDADD = ${LEXER_LIBS} \
							../src/lexer.o \
							-lcheck -lsubunit -lm -lrt -lpthread

parser_CFLAGS = -I/usr/include \
							  -I$(includedir)

parser_LDADD = ${PARSER_LIBS} \
							../src/lexer.o \
							 ../src/parser.o \
							 -lcheck -lsubunit -lm -lrt -lpthread

