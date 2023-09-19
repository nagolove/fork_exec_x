#!/usr/bin/env bash
nvim fork_exec.c &&  clang -o -g3 -fsanitize=address -o fork_exec fork_exec.c &&  ./fork_exec
