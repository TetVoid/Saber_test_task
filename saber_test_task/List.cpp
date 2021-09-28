#include "List.h"

void List::Serialize(FILE* file)
{
	std::string listInfo = std::to_string(count)+" "+ goDeep(head);

	fprintf(file, listInfo.c_str());
}

void List::Deserialize(FILE* file)
{
	int count;
	fscanf_s(file, "%d", &count);
	int* unicCodeMap = new int[count];
	int* randNotNullMap = new int[count];
	ListNode** lineMatrixOfNodePointers = new ListNode*[count];

	int mapIndex = 0;

	char *buffer=new char[10000];
	while (fscanf_s(file, "%d%s%d", &unicCodeMap[mapIndex], buffer, 10000, &randNotNullMap[mapIndex])!=-1)
	{
		lineMatrixOfNodePointers[mapIndex] = add(std::string(buffer));
		mapIndex++;
	}

	for (int i = 0; i < count; i++)
		if (randNotNullMap[i] != 0)
			for (int j = 0; j < count; j++)
				if (unicCodeMap[j] == randNotNullMap[i])
					lineMatrixOfNodePointers[i]->rand = lineMatrixOfNodePointers[j];
}

ListNode* List::add(std::string data)
{
	ListNode *node = new ListNode;
	node->next = NULL;
	node->prev = NULL;
	node->rand = NULL;
	
	node->data = data;
	if (count == 0)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
	count++;
	return node;
}

std::string List::goDeep(ListNode *node)
{
	std::string listInfo= "";
	listInfo += std::to_string(int(node)) + " ";
	listInfo += node->data + " ";
	listInfo += std::to_string(int(node->rand)) + "\n";

	if (node->next != NULL)
		listInfo += goDeep(node->next);

	return listInfo;
}