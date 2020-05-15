program exe_pilha;
const 
	MAX = 3;
type 
	Tvetor = array[1..MAX] of integer;
var 
	pilha : Tvetor;
	condicao : char;
	posicao, valor : integer;

procedure push (valor : integer);
begin
	if(posicao>MAX) then writeln('OverFlow') else
	begin
		posicao := posicao + 1;
		pilha[posicao] := valor;
	end;
end;

function pop : integer;
begin
	if(posicao<1) then writeln('UnderFlow') else
		begin
		pop := pilha[posicao];
		posicao := posicao - 1;
	end;
end;

procedure exibir;
begin
	writeln('___________________________________ ');
	
	writeln('Posicao na pilha :');
	for posicao:=1 to MAX do 
		begin
		writeln('Indice: ',posicao, ' = ',pilha[posicao]);
	end;
	writeln('___________________________________ ');
	
	writeln('Posicao na pilha a se retirada :');
	for posicao:=MAX downto 1 do 
		begin
	writeln('Indice: ',posicao, ' = ',pilha[posicao]);
	end;
end;

begin
	posicao := 0;
	
	repeat
		writeln('Deseja [A]dicionar , [R]etirar ou [S]air ?');
		readln(condicao);

		case condicao of
			'A','a' : begin 
				writeln('Valor ');
				readln(valor);
				push(valor);
			end;

			'r','R' : begin
				writeln('O valor = ',pop);
			end;
		end;
	until(condicao = 's') or (condicao = 'S');

	exibir;
end.