#include <stdio.h>
#include <stdlib.h>

struct Nodos {
	int data;
	struct Nodos* left;
	struct Nodos* right;
};

struct Nodos* createNode(int value) {
	struct Nodos* newNode = (struct Nodos*)malloc(sizeof(struct Nodos));
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Nodos* insert(struct Nodos* root, int value) {
	if (root == NULL) {
		return createNode(value);
	}

	if (value < root->data) {
		root->left = insert(root->left, value);
	} else if (value > root->data) {
		root->right = insert(root->right, value);
	}

	return root;
}
struct Nodos* search(struct Nodos* root, int value) {
	if (root == NULL || root->data == value) {
		return root;
	}

	printf("Comparando con %d\n", root->data);

	if (value < root->data) {
		return search(root->left, value);
	}

	return search(root->right, value);
}

void inorderTraversal(struct Nodos* root) {
	if (root != NULL) {
		inorderTraversal(root->left);
		printf("%d ", root->data);
		inorderTraversal(root->right);
	}
}

int main() {
	int x;
	struct Nodos* root = NULL;

	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	insert(root, 10);
	insert(root, 25);
	insert(root, 42);
	insert(root, 69);

	printf("Recorrido Inorden: ");
	inorderTraversal(root);
	printf("\n");
	
	printf("ingrese un numero para buscar en el arbol de busqueda\n");
	
	scanf("%i",&x);

	int searchValue = x;
	struct Nodos* result = search(root, searchValue);

	if (result != NULL) {
		printf("%d encontrado en el árbol.\n", searchValue);
	} else {
		printf("%d no encontrado en el arbol.\n", searchValue);
	}

	return 0;
}