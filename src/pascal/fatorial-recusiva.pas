program fatorial_recursiva;
var
	num : longint;

function fatorial (number : longint): longint;
begin
    if (number = 1) then
        fatorial := 1
    else 
        fatorial := number * fatorial(number-1)
end;

function fatorialb(n:integer): integer;
begin
	if n > 1 then
		fatorial := fatorial(n-1) * n
	else fatorial := 1;
end;

begin
    writeln('Informe um numero');
    readln(num);
    writeln(' ');

    writeln(num,'! = ',fatorial(num));
end.