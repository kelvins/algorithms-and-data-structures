program mergeSort;

const
  MAX = 10;
  SENTINELA = 3200;

type
	Tdado = integer;

	Tvetor = array[1..MAX] of Tdado;
	TvetorSentinela = array[1..MAX+1] of Tdado;

var
	vetor : Tvetor;
	
procedure auto(var vetor:Tvetor);
var
	i : integer;
begin
	for i := 1 to MAX do
	begin
		vetor[i]:=random(150);
	end;
end;
 
procedure exibir(vetor: Tvetor);
var
	i : integer;
begin
	writeln;
	write(' | ');
	for i:=1 to MAX do
	begin
		write(vetor[i]);
		write(' | ');
	end;
	writeln;
end;

procedure merge(var vetor:Tvetor; inicio:integer; meio:integer; fim:integer);
var
	e, d, i : integer;
	esquerda : integer;
	direita : integer;
	left : TvetorSentinela;
	right : TvetorSentinela;
	 
begin
	//final de cada vetor temporario
	esquerda := (meio - inicio +1);
	direita := (fim - meio);
	// vetor temporario recebendo seus valores respectivos
	for e := 1 to esquerda do 
		left[e] := vetor[inicio+e-1];
	for d := 1 to direita do 
		right[d] := vetor[meio+d];
	//para determinar qtos trocas	
	left[esquerda+1] := SENTINELA;
	right[direita+1] := SENTINELA;
	
	e := 1;
	d := 1;
	//unir(merge) os vetores os ordena-os
	for i := inicio to fim do
	begin
		// qual lado e maior q o outro
		if (left[e] <= right[d]) then
		begin
			vetor[i] := left[e];
			e := e+1;
		end else
		begin
			vetor[i] := right[d];
			d:= d+1;
		end;
	end; 
end;

procedure dividir(var vetor : Tvetor; inicio:integer; fim:integer);
var 
	meio : integer;
begin
	//merge
	//write('merge');
	//writeln;
	//writeln(inicio);
	//writeln(fim);
	if (inicio < fim) then
	begin
		meio := (inicio+fim) div 2;
		//esquerda
		dividir(vetor, inicio, meio);
		//direita
		dividir(vetor, meio+1, fim);
		//chama o merge, após termina as recursões acima.
		merge(vetor,inicio, meio, fim);
	end;
end;
  
begin	
	auto(vetor);
	exibir(vetor);
	dividir(vetor, 1, MAX);
	exibir(vetor);
end.