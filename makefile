all: conductor.c performer.c
	gcc -o conductor conductor.c -lao -ldl -lm
	gcc -o performer performer.c -lao -ldl -lm
