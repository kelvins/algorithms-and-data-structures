program SinglyLinkedList;

uses
  System.SysUtils;

type
  PNode = ^TNode;

  TNode = Record
    Data: Variant;
    Next: PNode;
  End;

  TSinglyLinkedList = Class
    private
      FHead: PNode;

      function AllocNode: Pointer;
      procedure FreeNode(var ANode: PNode);
    public
      property Head: PNode read FHead write FHead;

      procedure Append(AValue: Variant);
      procedure Remove(AValue: Variant);
      procedure Print;

      constructor Create; overload;
      constructor Create(AHead: PNode); overload;
      constructor Create(AHeadValue: Variant); overload;
  End;

{ TSinglyLinkedList }

function TSinglyLinkedList.AllocNode: Pointer;
begin
  Result:= AllocMem(SizeOf(TNode));
end;

procedure TSinglyLinkedList.FreeNode(var ANode: PNode);
begin
  FreeMem(ANode);
  ANode:= nil;
end;

procedure TSinglyLinkedList.Append(AValue: Variant);
var
  nLast: PNode;
begin
  if FHead = nil then
  begin
    FHead     := AllocNode;
    FHead.Data:= AValue;
    Exit;
  end;

  nLast:= FHead;

  while nLast.Next <> nil do
    nLast:= nLast.Next;

  if nLast.Next = nil then
  begin
    nLast.Next     := AllocNode;
    nLast.Next.Data:= AValue;
  end;
end;

procedure TSinglyLinkedList.Remove(AValue: Variant);
var
  nLeft, nCurrent: PNode;
begin
  nCurrent:= FHead;
  nLeft   := nil;

  while (nCurrent.Next <> nil) and (nCurrent.Data <> AValue) do
  begin
    nLeft   := nCurrent;
    nCurrent:= nCurrent.Next;
  end;
  if nLeft = nil then
    FHead:= nCurrent.Next
  else
    nLeft.Next:= nCurrent.Next;
  FreeNode(nCurrent);
end;

procedure TSinglyLinkedList.Print;
var
  nAux: PNode;
begin
  nAux:= FHead;

  if nAux = nil then
    Exit;

  while (nAux <> nil) do
  begin
    Writeln('Valor: ', nAux^.Data);
    nAux:= nAux.Next;
  end;
end;

constructor TSinglyLinkedList.Create;
begin
  FHead:= nil;
end;

constructor TSinglyLinkedList.Create(AHead: PNode);
begin
  Create;
  if AHead <> nil then
  begin
    FreeNode(FHead);
    FHead:= AHead;
  end;
end;

constructor TSinglyLinkedList.Create(AHeadValue: Variant);
begin
  Create;
  FHead     := AllocNode;
  FHead.Data:= AHeadValue;
end;

var
  lList: TSinglyLinkedList;

begin

  lList:= TSinglyLinkedList.Create;

  lList.Append(1);
  lList.Append(4);
  lList.Append(2);
  lList.Append(3);

  Writeln('Lista criada: ');
  lList.Print;

  Writeln('Removendo valor 4');
  lList.Remove(4);
  lList.Print;

  Readln;
end.
