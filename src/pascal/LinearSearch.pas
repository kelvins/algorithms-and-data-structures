program LinearSearchP;

uses
  System.SysUtils;

function LinearSearch(AArray: TArray<Variant>; AValue: Variant): integer;
var
  I: Integer;
begin
  Result:= -1;

  for I := 0 to Length(AArray)-1 do
  begin
    if AArray[I] = AValue then
    begin
      Result:= I;
      Exit;
    end;
  end;
end;

var
  lArr: TArray<Variant>;
begin

  Writeln('-- Criando Array: [1, 2, 3] --');
  lArr:= TArray<Variant>.Create(1, 2, 3);

  Writeln('-- Procurando pelo valor 2 --');
  Writeln('Localizado no índice: ', IntToStr(LinearSearch(lArr, 2)));

  Writeln('-- Procurando pelo valor 4 --');
  Writeln('Localizado no índice: ', IntToStr(LinearSearch(lArr, 4)));

  Readln;
end.
