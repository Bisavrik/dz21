#include <iostream>
#include <filesystem>
using namespace std;

struct Product
{
	char name[50];
	double price;
	int quantity;
	bool availability;
};

void showProduct(Product& product)
{
	cout << "Name: " << product.name << endl;
	cout << "Price: " << product.price << endl;
	cout << "Quantity: " << product.quantity << endl;
	cout << "Availability: " << (product.availability ? "Yes" : "No") << endl;
}

int main()
{
	const char* PATH_TO_FILE = "product.txt";

	const int N = 5;
	Product product_list[N] = 
	{
		{"Product1", 10.99, 100, true},
		{"Product2", 15.99, 150, false},
		{"Product3", 12.49, 200, true},
		{"Product4", 8.99, 250, true},
		{"Product5", 9.99, 300, false}
	};

	FILE* file;

	if (fopen_s(&file, PATH_TO_FILE, "wb+") == 0)
	{
		fwrite(product_list, sizeof(Product), N, file);
		Product new_product_list[N]{};
		fseek(file, 0, SEEK_SET);
		fread(new_product_list, sizeof(Product), N, file);
		for (int i = 0; i < N; i++)
		{
			showProduct(new_product_list[i]);
		}
		fclose(file);
	}
}