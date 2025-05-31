#!/bin/bash
set -e

# 自动跳转到脚本所在目录
cd "$(dirname "$0")"

echo "==> Generating lex_sql.cpp and yacc_sql.cpp..."
flex --outfile=lex_sql.cpp --header-file=lex_sql.h lex_sql.l
bison -d --output=yacc_sql.cpp yacc_sql.y
echo "✅ Parser generation done."
