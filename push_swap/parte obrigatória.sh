parte obrigatória
Lembrete: Lembre-se que, durante a defesa, não há falta de seg, nem outro término inesperado, prematuro, descontrolado ou inesperado do programa, caso contrário, a nota final é 0. Use o sinalizador apropriado. Esta regra está ativa durante toda a defesa.

Perda de memória
Ao longo da defesa, preste atenção à quantidade de memória
usada pelo push_swap (usando o comando top, por exemplo) para
detectar qualquer anomalia e garantir que a memória alocada seja
devidamente liberada. Se houver um vazamento de memória (ou mais), a
nota final será 0.

gerenciamento de erros
Nesta seção, avaliaremos o gerenciamento de erros do push_swap.
Se pelo menos um falhar, nenhum ponto será concedido para esta
seção. Mover para o próximo.

Execute push_swap com parâmetros não numéricos. O programa deve
exibir "Erro".

Execute push_swap com um parâmetro numérico duplicado. O programa
deve exibir "Erro".

Execute push_swap apenas com parâmetros numéricos, incluindo um maior
que MAXINT. O programa deve exibir "Erro".

Execute push_swap sem nenhum parâmetro. O programa não deve
exibir nada e retornar o prompt.

Push_swap - Teste de identidade
Nesta seção, avaliaremos o comportamento de push_swap quando dada
uma lista, que já foi classificada. Execute os 3
testes a seguir. Se pelo menos um falhar, nenhum ponto será concedido para esta
seção. Mover para o próximo.

Execute o seguinte comando "$>./push_swap 42". O programa
não deve exibir nada (instrução 0).

Execute o seguinte comando "$>./push_swap 2 3". O
programa não deve exibir nada (instrução 0).

Execute o seguinte comando "$>./push_swap 0 1 2 3". O
programa não deve exibir nada (instrução 0).

Execute o seguinte comando "$>./push_swap 0 1 2 3 4 5 6 7 8
9". O programa não deve exibir nada (instrução 0).

Execute o seguinte comando "$>./push_swap 'Entre 0 e 9
valores classificados aleatoriamente escolhidos>'. O programa não deve exibir nada
(instrução 0).

Push_swap - versão simples
Se os seguintes testes falharem, nenhum ponto será concedido para esta
seção. Mover para o próximo. Use o binário do verificador fornecido nos
anexos.

Execute "$>ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG".
Verifique se o programa verificador exibe "OK" e se o
tamanho da lista de instruções de push_swap é 2 OU 3.
Caso contrário, o teste falha.

Execute "$>ARG="'Entre 0 e 3 valores escolhidos aleatoriamente'"; ./push_swap
$ARG | ./checker_OS $ARG". Verifique se o programa verificador exibe
"OK" e se o tamanho da lista de instruções de push_swap
está entre 0 E 3. Caso contrário, o teste falha.

Outra versão simples
Execute os 2 testes a seguir. Se pelo menos um falhar, nenhum ponto
será concedido para esta seção. Mover para o próximo. Use o
binário do verificador fornecido nos anexos.

Execute "$>ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG".
Verifique se o programa verificador exibe "OK" e se o
tamanho da lista de instruções de push_swap não é maior
que 12. Kudos se o tamanho da lista de instruções for 8.

Execute "$>ARG="<5 valores aleatórios>"; ./push_swap $ARG | ./checker_OS
$ARG" e substitua o espaço reservado por 5 valores aleatórios válidos.
Verifique se o programa verificador exibe "OK" e se o
tamanho da lista de instruções de push_swap não é maior
que 12. Caso contrário, este teste falhará. Você terá que
verificar especificamente se o programa não foi desenvolvido para
responder corretamente apenas no teste incluído nesta escala. Você
deve repetir este teste algumas vezes com várias
permutações antes de validá-lo.

Push_swap - versão intermediária
Se o teste a seguir falhar, nenhum ponto será concedido para esta
seção. Mover para o próximo. Mover para o próximo. Use o
binário do verificador fornecido nos anexos.

Execute "$>ARG="<100 valores aleatórios>"; ./push_swap $ARG | ./checker_OS $ARG" e substitua o espaço reservado por 100 valores aleatórios válidos. Verifique se o programa verificador exibe "OK" e o tamanho da lista de instruções. Dê pontos de acordo com:
menos de 700: 5
menos de 900: 4
menos de 1100: 3
menos de 1300: 2
inferior a 1500: 1 Terá de verificar especificamente que o programa não foi desenvolvido para responder corretamente apenas à prova incluída nesta escala. Você deve repetir este teste algumas vezes com várias permutações antes de validá-lo.
Avalie de 0 (falha) a 5 (excelente)

Push_swap - versão avançada
Se o teste a seguir falhar, nenhum ponto será concedido para esta
seção. Mover para o próximo. Mover para o próximo. Use o
binário do verificador fornecido nos anexos.

Execute "$>ARG="<500 valores aleatórios>"; ./push_swap $ARG | ./checker_OS $ARG" e substitua o espaço reservado por 500 valores aleatórios válidos (um não é chamado John/Jane Script à toa). Verifique se o programa verificador exibe "OK" e se o tamanho da lista de instruções
menos de 5500: 5
menos de 7000: 4
menos de 8500: 3
menos de 10000: 2
inferior a 11500: 1 Terá de verificar especificamente que o programa não foi desenvolvido para responder corretamente apenas ao teste incluído nesta escala. Você deve repetir este teste algumas vezes com várias permutações antes de validá-lo.
Avalie de 0 (falha) a 5 (excelente)

Bônus
Lembrete: Lembre-se que, durante a defesa, não há falta de seg, nem outro término inesperado, prematuro, descontrolado ou inesperado do programa, caso contrário, a nota final é 0. Use o sinalizador apropriado. Esta regra está ativa durante toda a defesa. Analisaremos seus bônus se e somente se sua parte obrigatória for EXCELENTE. Isso quer dizer que você deve cumprir a parte obrigatória, do começo ao fim, e seu gerenciamento de erros precisa ser impecável, mesmo em casos de uso distorcido ou mal feito. Portanto, se a parte obrigatória não marcou todos os pontos durante esta defesa, os bônus serão totalmente IGNORADOS.

Programa verificador - gerenciamento de erros
Nesta seção, avaliaremos o gerenciamento de erros do verificador.
Se pelo menos um falhar, nenhum ponto será concedido para esta
seção. Mover para o próximo.

Execute o verificador com parâmetros não numéricos. O programa deve
exibir "Erro".

Execute o verificador com um parâmetro numérico duplicado. O programa
deve exibir "Erro".

Execute o verificador apenas com parâmetros numéricos, incluindo um maior
que MAXINT. O programa deve exibir "Erro".

Execute o verificador sem nenhum parâmetro. O programa não deve
exibir nada e retornar o prompt.

Execute o verificador com parâmetros válidos e escreva uma ação que
não existe durante a fase de instrução. O programa deve
exibir "Erro".

Execute o verificador com parâmetros válidos e escreva uma ação com
um ou vários espaços antes e/ou depois da ação durante
a fase de instrução. O programa deve exibir "Erro".

Programa verificador - testes falsos
Nesta seção, avaliaremos a capacidade do verificador de gerenciar
uma lista de instruções que não classifica a lista. Execute os
2 testes a seguir. Se pelo menos um falhar, nenhum ponto será
concedido para esta seção. Mover para o próximo.

Não se esqueça de pressionar CTRL+D para interromper a leitura durante a
fase de instrução.

Execute o verificador com o seguinte comando "$>./checker 0 9 1 8 2
7 3 6 4 5" e escreva a seguinte lista de ações válidas "[sa,
pb, rrr]". O verificador deve exibir "KO".

Execute o verificador com uma lista válida como parâmetro de sua escolha e, em seguida,
escreva uma lista de instruções válidas que não ordene os
números inteiros. O verificador deve exibir "KO". Você terá que
verificar especificamente se o programa não foi desenvolvido para
responder corretamente apenas no teste incluído nesta escala. Você
deve repetir este teste algumas vezes com várias
permutações antes de validá-lo.

Programa verificador - testes corretos
Nesta seção, avaliaremos a capacidade do verificador de gerenciar
uma lista de instruções que classificam a lista. Execute os
2 testes a seguir. Se pelo menos um falhar, nenhum ponto será concedido para
esta seção. Mover para o próximo.

Não se esqueça de pressionar CTRL+D para interromper a leitura durante a
fase de instrução.

Execute o verificador com o seguinte comando "$>./checker 0 1 2"
e pressione CTRL+D sem escrever nenhuma instrução. O programa
deve exibir "OK".

Execute o verificador com o seguinte comando "$>./checker 0 9 1 8 2"
e escreva a seguinte lista de ações válidas "[pb, ra, pb, ra,
sa, ra, pa, pa]". O programa deve exibir "OK".

Execute o verificador com uma lista válida como parâmetro de sua escolha e, em seguida,
escreva uma lista de instruções válidas que ordene os números inteiros.
O verificador deve exibir "OK". Você terá que verificar especificamente
se o programa não foi desenvolvido para responder corretamente apenas no
teste incluído nesta escala. Você deve repetir este teste
algumas vezes com várias permutações antes de validá
-lo.