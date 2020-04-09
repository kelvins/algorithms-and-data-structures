program fatorial_pascal;
var
	num, cont, soma : longint;
begin
 soma := 1;
 cont := 0;
 writeln('Informe um numero');
 readln(num);
 writeln(' ');

 	for cont := num downto 2 do 
 	begin
 	 	//writeln(num*num-1);
 	 	writeln(soma);
 	 	soma := soma*cont;
 	 	writeln(soma);
    end;
  writeln(num,'! = ',soma);
end.