# 42sh

The last in a sequence of three shells, this one handles almost all types of command line. Made in collaboration with [Mickael Mazouz](https://github.com/mi-mazouz) and [Hugues Poncet](https://github.com/Mormoilbou)

Features included : redirections (as well as file redirection aggregation and heredoc), pipes, logical operators, commands separator, inhibitors, back quotes, globbing and autocompletion.

Builtins included : cd, echo, env, exit, export, history, read, setenv, unset, unsetenv.

A Line-edition is provided, thanks to the termcaps library, using the shortcuts below :

left/right arrows : move through the command line.

up/down arrows : move through history.

shift + left/right : move by word.

shift + up/down : move by line.

home : move to the command line's start.

end : move to the command line's end.

alt + s/x : copy/cut from the cursor to the end of the command line.

alt + d/c : copy/cut the whole command line.

alt + v : paste the buffer.
