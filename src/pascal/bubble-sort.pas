program selection_sort;

{dia 06/05
Version: 0.5
Nome: Wellington De Souza Silva
Método : Selection Sort}

// bug com dois valores altos ??? 

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
procedure kernel(var vetor : Tvetor); 
var
	j: integer;
	temp : integer;
begin
	for j:= 1 to MAX do 
	begin
		if vetor[j] > vetor[j+1] then
		begin
			temp := vetor[j];
			vetor[j] := vetor[j+1];
			vetor[j+1] := temp;
		end;
	end;
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
	for i:=MAX downto 1 do 
	begin
		kernel(vetor);
		exibir(vetor);
	end;
end;

begin
	preencher(vetor);
	writeln('Vetor Original');
	exibir(vetor);
	repetir();
	writeln;
	writeln('Vetor Ordenado');
	exibir(vetor);
end.