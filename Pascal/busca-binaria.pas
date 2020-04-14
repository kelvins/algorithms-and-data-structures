program buscabinaria;

const
    MAX = 30000;

type
    Tdado = integer;
    Tvetor = array[1..MAX]of integer;
	Tarq = text;
var 
  vetor : Tvetor;
  valor: Tdado;
	
procedure preencher(var vetor : Tvetor);
var
	i : integer;
begin
	for i:= 1 to MAX do
	begin	
		vetor[i] := i;
	end;
end;	

procedure buscaBinariarec(vetor:Tvetor; valor:Tdado; inicio:integer; fim:integer);
var 
	meio : integer;
begin
	meio := (inicio+fim) div 2;
	
    {
	writeln;	
	writeln('--------------------------------');
	writeln('Passo a Passo');
	writeln('valor	',vetor[meio]);
	writeln('posicao	',meio);
	writeln('--------------------------------');
	writeln;
    }
	
	if(valor = vetor[meio]) then
	begin
		writeln('Achou!!');
		//writeln('valor	',vetor[meio]);
		writeln('posicao	',meio);
	end else
		if(meio=inicio) then	write('error 404') else
		begin
		if((valor > vetor[meio]) and (meio <> inicio)) then
		begin
			//writeln('DIREITA');
			buscaBinariarec(vetor, valor, meio, MAX);
		end;
			
		if((valor < vetor[meio]) and (meio <> inicio)) then
		begin
			//writeln('ESQUERDA');
			buscaBinariarec(vetor, valor, inicio, meio);
		end;
	end;	
end;

begin
	valor := 21054;
	preencher(vetor);
	buscaBinariarec(vetor, valor, 0, MAX);
end.