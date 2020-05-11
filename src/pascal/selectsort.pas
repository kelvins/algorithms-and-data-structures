program selection_sort;

uses crt;

const
	MAX = 10;

type 
	Tdado = integer;

	Tvetor = array[1..MAX] of Tdado;
	
var
	vetor : Tvetor;

//usado para tester		
procedure preencher(var vetor : Tvetor);
begin
	vetor[1] := 4;
	vetor[2] := 3;
	vetor[3] := 500;
	vetor[4] := 7;
	vetor[5] :=	10;
	vetor[6] :=	1309;
	vetor[7] :=	8;
	vetor[8] :=	9;
	vetor[9] :=	2;
	vetor[10] := 6;
end;

procedure manual(var vetor:Tvetor);
var
	i : integer;
begin
	for i := 1 to MAX do
	begin
		writeln('informe o valor ',i);
		readln(vetor[i]);
	end;
end;
// acha o menor, nucleo do programa
procedure kernel(var vetor : Tvetor; pos : integer); 
var
	aux : integer=0;
	j: integer;
	menor : integer;
begin
	menor := pos;
	for j:= pos+1 to MAX do 
	begin
		if vetor[menor] > vetor[j] then
		begin
			menor := j;
			
		end;
	end;
	
	aux := vetor[pos];
	vetor[pos] := vetor[menor];
	vetor[menor] := aux;
end;

//////////////////////////////
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

procedure repetir();
var
	i: integer;
begin
	for i:=1 to MAX-1 do 
	begin
		kernel(vetor,i);
	end;
end;

begin
	manual(vetor);
	writeln('Vetor Original');
	exibir(vetor);
	repetir();
	writeln;
	writeln('Vetor Ordenado');
	exibir(vetor);
end.