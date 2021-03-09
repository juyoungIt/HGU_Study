#include <stdio.h>
#include <stdlib.h>

struct login_data * add_user();

struct login_data
{
	char id[20];
	char password[20];
};

main()
{
	struct login_data * user1;
	user1 = add_user();
	printf("입력받은 id : %s [passoword : %s]\n", user1->id, user1->password);
	return 0;
}

struct login_data * add_user()
{
	struct login_data * temp;
	temp = (struct login_data *) malloc(sizeof(struct login_data));
	printf("id는? : ");
	scanf("%s", temp->id);
	printf("password는? : ");
	scanf("%s", temp->password);

	return temp;
}