
# Arvore Binaria de Busca em Python
# Kelvin Salton do Prado
# 2015

class Arvore:
	def __init__(self, chave):
		self.chave    = chave;
		self.esquerda = None;
		self.direita  = None;

############# Metodos de Busca #############
def buscaRecursiva(no, chave):
	if no is None:
		print str(chave) + ' nao foi encontrado na arvore\n'
		return None
	if no.chave == chave:
		print str(chave) + ' foi encontrado na arvore\n'
		return no
	if chave > no.chave:
		buscaRecursiva(no.direita, chave)
	else:
		buscaRecursiva(no.esquerda, chave)

def buscaLinear(no, chave):
	while no is not None:
		if no.chave == chave:
			return no
		elif chave > no.chave:
			no = no.direita
		else:
			no = no.esquerda
	return None
############################################


############ Metodo de Insercao ############
def insere(no, chave):
	if no is None:
		no = Arvore(chave);
	else:
		if chave < no.chave:
			no.esquerda = insere(no.esquerda, chave);   
		else:
			no.direita  = insere(no.direita, chave);  
	return no;
############################################

########### Metodos de Impressao ###########
ImprimeArvore = ''

def preOrdem(no):
	global ImprimeArvore
	if no is None:
		return
	ImprimeArvore += str(no.chave) + ', '
	preOrdem(no.esquerda)
	preOrdem(no.direita)
	
def emOrdem(no):
	global ImprimeArvore
	if no is None:
		return
	emOrdem(no.esquerda)
	ImprimeArvore += str(no.chave) + ', '
	emOrdem(no.direita)

def posOrdem(no):
	global ImprimeArvore
	if no is None:
		return
	posOrdem(no.esquerda)
	posOrdem(no.direita)
	ImprimeArvore += str(no.chave) + ', '
############################################


######### Acha a Altura da Arvore ##########
def maximo(a, b):
	if a > b:
		return a
	return b

def altura(no):
	if no is None:
		return 0
	return 1 + maximo( altura(no.esquerda), altura(no.direita) )
############################################


########### Metodos de Exclusao ############
def buscaNoPai(no, ch):
	noPai = no
	while no is not None:
		if no.chave == ch:
			return noPai
		noPai = no
		if no.chave < ch:
			no = no.direita
		else:
			no = no.esquerda
	return noPai

def maiorAesquerda(no):
	no = no.esquerda
	while no.direita is not None:
		no = no.direita
	return no

def exclui(no, ch):
	atual = buscaLinear(no, ch)
	if atual is None:
		return False
	noPai = buscaNoPai(no, ch)
	if atual.esquerda is None or atual.direita is None:
		if atual.esquerda is None:
			substituto = atual.direita
		else:
			substituto = atual.esquerda
		if noPai is None:
			no = substituto
		elif ch > noPai.chave:
			noPai.direita = substituto
		else:
			noPai.esquerda = substituto
		# AQUI DA FREE(ATUAL)
	else:
		substituto = maiorAesquerda(atual)
		atual.chave = substituto.chave
		if substituto.esquerda is not None:
			atual.esquerda = substituto.esquerda
		else:
			atual.esquerda = None
		# FREE(substituto)
	return True
############################################

arvore = Arvore(3); # Cria arvore (raiz)
# Insere varios valores na arvore
arvore = insere(arvore, 2);
arvore = insere(arvore, 1);
arvore = insere(arvore, 4);
arvore = insere(arvore, 6);
arvore = insere(arvore, 8);
arvore = insere(arvore, 5);
arvore = insere(arvore, 7);
arvore = insere(arvore, 0);

buscaRecursiva(arvore, 6) # Busca que imprime na propria funcao

if buscaLinear(arvore, 6) is not None: # Retorna o NO ou None se nao encontrou
	print 'valor encontrado\n'
else:
	print 'valor nao encontrado\n'

print 'Altura : %d' % altura(arvore) # Retorna a altura da arvore (int)

# Exclui varios valores
exclui(arvore, 7)
exclui(arvore, 5)
exclui(arvore, 8)
exclui(arvore, 3)

# Chama os metodos de impressao
ImprimeArvore = ""
preOrdem(arvore)
print "PreOrdem: " + ImprimeArvore + "\n"
ImprimeArvore = ""
emOrdem(arvore)
print "EmOrdem: " + ImprimeArvore + "\n"
ImprimeArvore = ""
posOrdem(arvore)
print "PosOrdem: " + ImprimeArvore + "\n"

# Mostra a altura da arvore apos remover os itens
print 'Altura : %d' % altura(arvore)
