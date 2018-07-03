#include "Basket.h"
int main() {
	Basket bst;
	bst.add_item(Bulk_quote("aaa", 2.0, 5, 0.5));
	bst.add_item(Bulk_quote("aaa", 2.0, 5, 0.5));
	bst.add_item(Bulk_quote("aaa", 2.0, 5, 0.5));
	bst.add_item(Bulk_quote("aaa", 2.0, 5, 0.5));
	bst.add_item(Bulk_quote("aaa", 2.0, 5, 0.5));
	bst.add_item(Bulk_quote("aaa", 2.0, 5, 0.5));
	bst.total_receipt(cout);
	system("pause");
	return 0;
}