git#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdbool.h>
#include<stdlib.h>

#define SIZE 100



struct user_info{
    char user_name[SIZE];
    unsigned long int user_phone;
    char user_address[SIZE];
};

struct r_address{
    char street[SIZE];
    char area[SIZE];
};
struct generic_food{
    char food_item[SIZE];
    int price;
    int service_time;
};

struct special_item{
    char sfood_item[SIZE];
    int sprice;
    int s_service_time;
};

struct special_item_day{
    char sdfood_item[SIZE];
    int sdprice;
    int sd_service_time;
};

struct list_restaurant {
    char restaurant_name[SIZE];
    struct r_address ad;
    struct generic_food generic_foods[SIZE];
    struct special_item special_items[SIZE];
    struct special_item_day special_items_day[SIZE];
    int n_gen_dishes;
    int n_special_dishes;
    int n_special_dishes_day;
};
//checking the password/
bool isvalid(){
      int i=3;
      char password[100]="ABC@123";
      char input[100];
      bool ans=false;
      int flag=1;
      while(i>0 && flag==1){
      printf("%d chances left:\n",i);
      printf("Enter the password:\n");
      scanf("%s",input);
      if(strcmp(input,password)==0){
        ans=true;
        flag=0;
      }
      else{
        i--;
      }
      }
      return ans;
}

int partition_r_name(struct list_restaurant lr[],char x[], int high)
{
    int i,j;
    struct list_restaurant temp;
    i=0;
    j=high;
    while(i<j && strcmp(lr[i].restaurant_name,x)<=0)
        i++;
    while(i<j && strcmp(lr[j].restaurant_name,x)>0)   
        j--;
    if(strcmp(lr[j].restaurant_name,x)>0)   
        j=j-1;
    while(i<j)
    {
        temp=lr[i];
        lr[i]=lr[j];
        lr[j]=temp;
        i++;
        j--;
        while(strcmp(lr[i].restaurant_name,x)<=0)
            i++;
        while(strcmp(lr[j].restaurant_name,x)>0)   
            j--;
    }
      return j;
    }

void quicksort_r_name(struct list_restaurant lr[],int low, int high)
{
    int pi;
    struct list_restaurant temp;
    if(low<high)
    {
        pi=partition_r_name(lr,lr[low].restaurant_name,high);
        temp=lr[pi];
        lr[pi]=lr[low];
        lr[low]=temp;
        quicksort_r_name(lr,low,pi-1);
        quicksort_r_name(lr,pi+1,high);
    }
}


int partition_gf(struct generic_food gf[],char x[], int high)
{
    int i,j;
    struct generic_food temp;
    i=0;
    j=high;
    while(i<j && strcmp(gf[i].food_item,x)<=0)
        i++;
    while(i<j && strcmp(gf[j].food_item,x)>0)   
        j--;
    if(strcmp(gf[j].food_item,x)>0)   
        j=j-1;
    while(i<j)
    {
        temp=gf[i];
        gf[i]=gf[j];
        gf[j]=temp;
        i++;
        j--;
        while(strcmp(gf[i].food_item,x)<=0)
            i++;
        while(strcmp(gf[j].food_item,x)>0)   
            j--;
    }
      return j;
    }

void quicksort_gf(struct generic_food gf[],int low, int high)
{
    int pi;
    struct generic_food temp;
    if(low<high)
    {
        pi=partition_gf(gf,gf[low].food_item,high);
        temp=gf[pi];
        gf[pi]=gf[low];
        gf[low]=temp;
        quicksort_gf(gf,low,pi-1);
        quicksort_gf(gf,pi+1,high);
    }
}

int partition_sf(struct special_item si[],char x[], int high)
{
    int i,j;
    struct special_item temp;
    i=0;
    j=high;
    while(i<j && strcmp(si[i].sfood_item,x)<=0)
        i++;
    while(i<j && strcmp(si[j].sfood_item,x)>0)   
        j--;
    if(strcmp(si[j].sfood_item,x)>0)   
        j=j-1;
    while(i<j)
    {
        temp=si[i];
        si[i]=si[j];
        si[j]=temp;
        i++;
        j--;
        while(strcmp(si[i].sfood_item,x)<=0)
            i++;
        while(strcmp(si[j].sfood_item,x)>0)   
            j--;
    }
      return j;
    }

void quicksort_sf(struct special_item si[],int low, int high)
{
    int pi;
    struct special_item temp;
    if(low<high)
    {
        pi=partition_sf(si,si[low].sfood_item,high);
        temp=si[pi];
        si[pi]=si[low];
        si[low]=temp;
        quicksort_sf(si,low,pi-1);
        quicksort_sf(si,pi+1,high);
    }
}
int partition_sfd(struct special_item_day sid[],char x[], int high)
{
    int i,j;
    struct special_item_day temp;
    i=0;
    j=high;
    while(i<j && strcmp(sid[i].sdfood_item,x)<=0)
        i++;
    while(i<j && strcmp(sid[j].sdfood_item,x)>0)   
        j--;
    if(strcmp(sid[j].sdfood_item,x)>0)   
        j=j-1;
    while(i<j)
    {
        temp=sid[i];
        sid[i]=sid[j];
        sid[j]=temp;
        i++;
        j--;
        while(strcmp(sid[i].sdfood_item,x)<=0)
            i++;
        while(strcmp(sid[j].sdfood_item,x)>0)   
            j--;
    }
      return j;
    }

void quicksort_sfd(struct special_item_day sid[],int low, int high)
{
    int pi;
    struct special_item_day temp;
    if(low<high)
    {
        pi=partition_sfd(sid,sid[low].sdfood_item,high);
        temp=sid[pi];
        sid[pi]=sid[low];
        sid[low]=temp;
        quicksort_sfd(sid,low,pi-1);
        quicksort_sfd(sid,pi+1,high);
    }
}

//used in placing order for finding the food is available or not/
int food_re(struct list_restaurant r[],int mid){
    char fooditem[100];
    printf("Enter the food item you want to search:\n");
    getchar();
    fgets(fooditem,SIZE,stdin);
    int n=-1;
    int flag=0;
    for(int j=0;j<r[mid].n_gen_dishes && flag==0;j++)
        {
            if(strcmp(r[mid].generic_foods[j].food_item,fooditem)==0)
            {
                n=j;
                flag=1;
            }
        }
        
    for(int j=0;j<r[mid].n_special_dishes && flag==0;j++)
        {
            if(strcmp(r[mid].special_items[j].sfood_item,fooditem)==0)
            {
                n=j;
            }
        }
        for(int j=0;j<r[mid].n_special_dishes_day && flag==0;j++)
        {
            if(strcmp(r[mid].special_items_day[j].sdfood_item,fooditem)==0)
            {
                n=j;
            }
        }
        return n;
}

int BinarySearch(struct list_restaurant r[], int s,int e, char x[]) {
    int flag = 1;
    int ans = -1;
    int mid;

    while (s <= e && flag == 1) {
        mid = (s + e)/ 2;  // Calculate mid within the loop

        if (strcmp(r[mid].restaurant_name, x) == 0) {
            ans = mid;
            flag = 0;
        } else if (strcmp(r[mid].restaurant_name,x) < 0) {
            // Update e if the target string is in the left half
            s = mid+1 ;
        } else {
            // Update s if the target string is in the right half
            e = mid -1;
        }
    }

    return ans;
}

void SwapRestaurants(struct list_restaurant *a, struct list_restaurant *b) {
    struct list_restaurant temp;
    memcpy(&temp, a, sizeof(struct list_restaurant));
    memcpy(a, b, sizeof(struct list_restaurant));
    memcpy(b, &temp, sizeof(struct list_restaurant));
}
//sort the restaurant
void SortRestaurant(struct list_restaurant r[],int n){
     


        quicksort_r_name(r,0, n-1);
        
         printf("Restaurant in Sorted Order is AS follows:\n");
         for(int i=0;i<n;i++){
            if(strcmp(r[i].restaurant_name,r[i+1].restaurant_name)==0){
                  if(strcmp(r[i].ad.area, r[i+1].ad.area)>0){
                    SwapRestaurants(&r[i],&r[i+1]);
                  }  
            }
         }
         
          for(int i=0;i<n;i++){
            printf("%s %s\n",r[i].restaurant_name,r[i].ad.area);
            }
         }
//It gives minimum time the dish can be delivered to you/
void getMinTime(struct list_restaurant r[],int n){
    char fooditem[100];
    printf("Enter the food item:\n");
    getchar();
    fgets(fooditem,SIZE,stdin);
    
    int quantity;
    printf("Enter the quantity:\n");
    scanf("%d",&quantity);
    int min=1000;
    char min_rest_name[100]="";
    char min_address[100]="";
    for(int i=0;i<n;i++){
        for(int j=0;j<r[i].n_gen_dishes;j++)
        {
            if(strcmp(r[i].generic_foods[j].food_item,fooditem)==0)
            {
                if (r[i].generic_foods[j].service_time<min)
                {
                    min=r[i].generic_foods[j].service_time;
                    strcpy(min_rest_name,r[i].restaurant_name);
                    strcpy(min_address,r[i].ad.street);
                    strcat(min_address, r[i].ad.area);
                }
            }
        }
        
        for(int j=0;j<r[i].n_special_dishes;j++)
        {
            if(strcmp(r[i].special_items[j].sfood_item,fooditem)==0)
            {
                 if (r[i].special_items[j].s_service_time<min)
                {
                    min=r[i].special_items[j].s_service_time;
                    strcpy(min_rest_name,r[i].restaurant_name);
                    strcpy(min_address,r[i].ad.street);
                    strcat(min_address, r[i].ad.area);
                }
            }
        }
        
        
    
        for(int j=0;j<r[i].n_special_dishes_day;j++)
        {
            if(strcmp(r[i].special_items_day[j].sdfood_item,fooditem)==0)
            {
                   if (r[i].special_items_day[j].sd_service_time<min)
                   {
                       min=r[i].special_items_day[j].sd_service_time;
                       strcpy(min_rest_name,r[i].restaurant_name);
                       strcpy(min_address,r[i].ad.street);
                       strcat(min_address, r[i].ad.area);
                    }
            }   
        }
        
    }
     if(min!=1000)
     {    
        printf("Restaurant name is: %s\n",min_rest_name);  
        printf("Restaurant address is: %s\n",min_address);  
        printf("Restaurant delivery time is: %d minutes\n",min);  
     }
     else
         printf("Sorry given food is not available :( \n");
}

//checks whether given item is available or not/
void getItemAvailability(struct list_restaurant r[],int n){
    char fooditem[100];
    printf("Enter the food item you want to search:\n");
    getchar();
    fgets(fooditem,SIZE,stdin);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r[i].n_gen_dishes;j++)
        {
            if(strcmp(r[i].generic_foods[j].food_item,fooditem)==0)
            {
                printf("Restaurant name: %s",r[i].restaurant_name);
                printf("Price: %d\n",r[i].generic_foods[j].price);
                printf("\n");
                
                flag=1;
            }
        }
        
        for(int j=0;j<r[i].n_special_dishes;j++)
        {
            if(strcmp(r[i].special_items[j].sfood_item,fooditem)==0)
            {
                printf("Restaurant name: %s",r[i].restaurant_name);
                printf("Price: %d\n",r[i].special_items[j].sprice);
                printf("\n");
                flag=1;
            }
        }
        
    for(int j=0;j<r[i].n_special_dishes_day;j++)
        {
            if(strcmp(r[i].special_items_day[j].sdfood_item,fooditem)==0)
            {
                printf("Restaurant name: %s",r[i].restaurant_name);
                printf("Price: %d\n",r[i].special_items_day[j].sdprice);
                printf("\n");
                flag=1;
            }
            
        }
        
    }
    if(flag==0)
    {
        printf("Given food is not available :( \n");
    }
}
//For placing your order/
void PlaceOrder(struct list_restaurant r[],int n,int user_no){
    char restaurantname[SIZE];
    struct user_info u[SIZE];
    getchar();
    printf("Enter User Name: ");
    fgets(u[user_no].user_name,SIZE,stdin);
    
    printf("Enter Phone Number: ");
    scanf("%lu",&u[user_no].user_phone);
    getchar();
    printf("Enter User Address: ");
    fgets(u[user_no].user_address,SIZE,stdin);
    printf("Restaurants currently taking order: \n");
    for(int i=0;i<n;i++)
        printf("%s", r[i].restaurant_name);
    
    printf("Enter Restaurant Name:\n");
    fgets(restaurantname,SIZE,stdin);
    
    int mid=BinarySearch(r,0,n-1,restaurantname);
    
    if(mid==-1){
        printf("Invalid Restaurant Name:\n");
        
    }
    char ans='y';
    int a;
    int qt;
    
    if(mid!=-1){
       do
        {
        printf("All Available Food Item in the Restaurant are:\n");
         
        for(int j=0;j<r[mid].n_gen_dishes;j++){
            printf("%s\n",r[mid].generic_foods[j].food_item);
        }
        
        for(int j=0;j<r[mid].n_special_dishes;j++)
        {
            printf("%s\n",r[mid].special_items[j].sfood_item);
        }
        for(int j=0;j<r[mid].n_special_dishes_day;j++)
        {
            printf("%s\n",r[mid].special_items_day[j].sdfood_item);
        }
        
        
            a=food_re(r,mid);
            if(a==-1)
            {
                 printf("Sorry, it is not available!!");
            }
             
            else
            {  printf("Enter the quantity: ");
              scanf("%d",&qt);
            }
            printf("Want to order more items? [y/n]");
            scanf(" %c",&ans);
        }
        while(ans=='y');
    }    
    int id = rand() % 9000 + 1000;
    
       printf("Thanks for ordering!!\n");
       printf("\nHave a nice day :)\n");
       printf("Your order ID no is %d\n: ",id);
       
    }
    
//Print all the generic food item using quick sort of the given restaurant/
void getItemListInSortedOrder(struct list_restaurant r[],int n)
{
    char r_name[100];
    printf("Enter the name of restaurant to: ");
    getchar();
    fgets(r_name,SIZE,stdin);
    int mid=BinarySearch(r,0,n-1,r_name);
    if(mid==-1){
        printf("Invalid Restaurant Name:\n");
    }
    
    if(mid!=-1){
        quicksort_gf(r[mid].generic_foods,0, r[mid].n_gen_dishes-1);
        
         printf("Generic Food In sorted Order is as follows:\n ");
         
        for(int j=0;j<r[mid].n_gen_dishes;j++){
            printf("%s\n",r[mid].generic_foods[j].food_item);
        }
        if(r[mid].n_gen_dishes==0)
            printf("No generic food in given restaurant!!\n");
        
    }
}

//Print all the food item available in the given area/
void getItemListInAreaSortedOrder(struct list_restaurant r[],int n){
    char area[SIZE];
    printf("Enter the area:\n");
    getchar();
    fgets(area,SIZE,stdin);
    int a=0;
    printf("Generic Food in Area Are:\n");
    for(int i=0;i<n;i++){
        if(strcmp(r[i].ad.area,area)==0){
            a=1;
            for(int j=0;j<r[i].n_gen_dishes;j++){
                printf("%s\n",r[i].generic_foods[j].food_item);
            }
        }
    }
    if(a==0)
             printf("No restaurant in this area which serves generic of the day!!");
    printf("Special Item Available in the Area are:\n");
    int b=0; //check whether any restaurant present in that area/
    for(int i=0;i<n;i++){
       if(strcmp(r[i].ad.area,area)==0)
        {
            b=1;
            for(int j=0;j<r[i].n_special_dishes;j++)
            {
               printf("%s\n",r[i].special_items[j].sfood_item);
            }
        }
    }
    if(b==0)
        printf("No restaurant in this area which serves special item!!");
        
    printf("Special Item of Day in the Area are:\n");
    int c=0; //check whether any restaurant present in that area/
    for(int i=0;i<n;i++)
    {
        if(strcmp(r[i].ad.area,area)==0)
        {
           c=1;    
           for(int j=0;j<r[i].n_special_dishes_day;j++)
            {
                printf("%s\n",r[i].special_items_day[j].sdfood_item);
            }
        }
    }
    if(c==0)
        printf("No restaurant in this area which serves special item of the day!!");
}
    
/* it sort all special items using quick sort and prints food item of the given restaurant"*/
void getAllSpecialItemListinSortedOrder(struct list_restaurant r[],int n){
    char r2_name[SIZE];
    printf("Enter the name of restaurant to: ");
    getchar();
    fgets(r2_name,SIZE,stdin);
    
    
 int mid=BinarySearch(r,0,n-1,r2_name);
 
    if(mid==-1){
        printf("Invalid Restaurant Name:\n");
    }
    
    if(mid!=-1){
        quicksort_sf(r[mid].special_items,0, r[mid].n_special_dishes-1);
        
         printf("Generic Food In sorted Order is as follows:\n ");
         
        for(int j=0;j<r[mid].n_special_dishes;j++){
            printf("%s\n",r[mid].special_items[j].sfood_item);
        }
        if(r[mid].n_special_dishes==0)
            printf("No special items in this restaurant!!");
        
    }
    
}

//it sorts all item of the day using quick sort and prints it of the given restaurant/
void getItemofDayListinSortedOrder(struct list_restaurant r[],int n) {
    
    char r_name[100];
    printf("Enter the name of restaurant to: ");
    getchar();
    fgets(r_name,SIZE,stdin);
    
    
 int mid=BinarySearch(r,0,n-1,r_name);
    
    if(mid==-1){
        printf("Invalid Restaurant Name:\n");
    }
    
    if(mid!=-1){
        quicksort_sfd(r[mid].special_items_day,0, r[mid].n_special_dishes_day-1);
        
         printf("Generic Food In sorted Order is as follows:\n ");
         
        for(int j=0;j<r[mid].n_special_dishes_day;j++)
        {
            printf("%s\n",r[mid].special_items_day[j].sdfood_item);
        }
        if(r[mid].n_special_dishes_day==0)
            printf("No special item of the day!!");
    }
}
//Shows all the common dishes from the restaurants given by user/
void getCommonItem(struct list_restaurant r[], int n) {
    int inputs;
    printf("Enter Number of Restaurants:\n");
    scanf("%d", &inputs);
    char rest_names[inputs][SIZE]; // Array to store restaurant names
    int mid[inputs];
    int val[inputs];
    int p=0;
    int c=0;
    

    // Input restaurant names
    getchar();
    for (int i = 0; i < inputs; i++) { 
        printf("Enter name of Restaurant %d:\n", i + 1);
        fgets(rest_names[i], SIZE, stdin);
    }

    // Find midpoints for each restaurant using BinarySearch
    for (int i = 0; i < inputs; i++) { // Loop up to inputs, not n-1
        mid[i] = BinarySearch(r, 0, n - 1, rest_names[i]);
        quicksort_gf(r[mid[i]].generic_foods,0, r[mid[i]].n_gen_dishes-1);
        quicksort_sf(r[mid[i]].special_items,0, r[mid[i]].n_special_dishes-1);
        quicksort_sfd(r[mid[i]].special_items_day,0, r[mid[i]].n_special_dishes_day-1);
        
    }

    printf("Common Generic Food Items are as follows:\n");
    // Compare common items between all pairs of restaurants
    for (int i = 0; i < r[mid[0]].n_gen_dishes; i++) 
    {
        int count = 1; // Initialize count inside this loop
        for (int j = 1; j < inputs; j++) 
        { // Loop up to inputs, not n
            val[0]=i;
            for (int k = 0; k < r[mid[j]].n_gen_dishes; k++) 
            {
                p=1;
                if (strcmp(r[mid[0]].generic_foods[i].food_item, r[mid[j]].generic_foods[k].food_item) == 0) {
                    val[p]=k;
                    printf("%d",p);     
                    p++;  
                               
                    count++;
                }
            }
        }
        if (count == inputs) {
            c=1;
            printf("Common item is %s\n", r[mid[0]].generic_foods[i].food_item);
            for(int l=0;l<inputs;l++)
            {
                printf("Restaurant name: %s",r[mid[l]].restaurant_name);
                printf("Price: %d\n", r[mid[l]].generic_foods[val[l]].price);
            }    
        }
       
    }
    
    printf("Special Food Items are as follows:\n");
       for (int i = 0; i < r[mid[0]].n_special_dishes; i++) {
        val[0]=i;   
        int count = 1; // Initialize count inside this loop
        for (int j = 1; j < inputs; j++) { // Loop up to inputs, not n
            for (int k = 0; k < r[mid[j]].n_special_dishes;k++) {
                p=1;
                if (strcmp(r[mid[0]].special_items[i].sfood_item, r[mid[j]].special_items[k].sfood_item) == 0) {
                    val[p]=k;  
                    p++; 
                    count++;
                }
            }
        }
    
        if (count == inputs) {
            c=1;
            printf("Common item is %s\n", r[mid[0]].special_items[i].sfood_item);
            for(int l=0;l<inputs;l++)
            {
                printf("Restaurant name: %s",r[mid[l]].restaurant_name);
                printf("Price: %d\n", r[mid[l]].special_items[val[l]].sprice);
            }  
        }
       
    }
   printf("Special Food Items of Day are as follows:\n");
       for (int i = 0; i < r[mid[0]].n_special_dishes_day; i++) {
        val[0]=i;   
        int count = 1; // Initialize count inside this loop
        for (int j = 1; j < inputs; j++) { // Loop up to inputs, not n
            p=1;
            for (int k = 0; k < r[mid[j]].n_special_dishes_day; k++) {
                if (strcmp(r[mid[0]].special_items_day[i].sdfood_item, r[mid[j]].special_items_day[k].sdfood_item) == 0) {
                    val[p]=k;  
                    p++; 
                    count++;
                }
            }
        }

        if (count == inputs) {
            c=1;
            printf("Common item is %s\n", r[mid[0]].special_items_day[i].sdfood_item);
            for(int l=0;l<inputs;l++)
            {
                printf("Restaurant name: %s",r[mid[l]].restaurant_name);
                printf("Price: %d\n", r[mid[l]].special_items_day[val[l]].sdprice);
            }  
        }
    }
    if(c==0)
        printf("No common items!!");
}


void getAllUniqueItem(struct list_restaurant r[],int n){
    char r1[SIZE];
    char r2[SIZE];
    
    printf("Enter the Restaurant 1 Name:\n");
    getchar();
    fgets(r1,SIZE,stdin);
    
    printf("Enter Restaurant 2 Name:\n");
    fgets(r2,SIZE,stdin);
    
    int mid1=BinarySearch(r,0,n-1,r1);
    int mid2=BinarySearch(r,0,n-1,r2);
    
    if(mid1==-1 || mid2==-1){
        printf("Invalid Restaurant name:\n");
    }
    
    
  if(mid1!=-1 && mid2!=-1){ 
     quicksort_gf(r[mid1].generic_foods,0, r[mid1].n_gen_dishes-1);
     quicksort_sf(r[mid1].special_items,0, r[mid1].n_special_dishes-1);
     quicksort_sfd(r[mid1].special_items_day,0, r[mid1].n_special_dishes_day-1); 
     quicksort_gf(r[mid2].generic_foods,0, r[mid2].n_gen_dishes-1);
     quicksort_sf(r[mid2].special_items,0, r[mid2].n_special_dishes-1);
    quicksort_sfd(r[mid2].special_items_day,0, r[mid2].n_special_dishes_day-1);
     int i = 0, j = 0;
    printf("Unique Generic Food Items are as follows:\n");
    
    while (i < r[mid1].n_gen_dishes && j < r[mid2].n_gen_dishes) {
        int cmp = strcmp(r[mid1].generic_foods[i].food_item, r[mid2].generic_foods[j].food_item);
        if (cmp == 0) {
            i++;
            j++;
        } else if (cmp < 0) {
            printf("%s",r[mid1].generic_foods[i].food_item);
            printf("Price is %d\n",r[mid1].generic_foods[i].price);
            printf("Address: %s", r[mid1].ad.area);
            i++;
            printf("\n");
        } else {
            printf("%s",r[mid2].generic_foods[j].food_item);
            printf("Price is %d\n",r[mid2].generic_foods[j].price);
            printf("Address: %s", r[mid2].ad.area);
             printf("\n");
            j++;
        }
    }
    while(i<r[mid1].n_gen_dishes){
         printf("%s",r[mid1].generic_foods[i].food_item);
         printf("Price is %d\n",r[mid1].generic_foods[i].price);
         printf("Address: %s", r[mid1].ad.area);
        i++;
         printf("\n");
    }
    while(j<r[mid2].n_gen_dishes){
         printf("%s",r[mid2].generic_foods[j].food_item);
         printf("Price is %d\n",r[mid2].generic_foods[j].price);
         printf("Address: %s", r[mid2].ad.area);
        j++;
         printf("\n");
    }
    
    printf("Unique Special Food Items are as follows:\n");
    i=0;
    j=0;
    
       while (i < r[mid1].n_special_dishes && j < r[mid2].n_special_dishes) {
        int cmp = strcmp(r[mid1].special_items[i].sfood_item, r[mid2].special_items[j].sfood_item);
        if (cmp == 0) {
            i++;
            j++;
        } else if (cmp < 0) {
            printf("Restaurant name: %s",r[mid1].restaurant_name);
            printf("Dish: %s",r[mid1].special_items[i].sfood_item);
            printf("Price is %d\n",r[mid1].special_items[i].sprice);
            printf("Address: %s", r[mid1].ad.area);
            i++;
             printf("\n");
        } else {
            printf("Restaurant name: %s",r[mid2].restaurant_name);
            printf("Dish: %s",r[mid2].special_items[j].sfood_item);
            printf("Price is %d\n",r[mid2].special_items[j].sprice);
            printf("Address: %s", r[mid2].ad.area);
            j++;
             printf("\n");
        }
    }
    while(i<r[mid1].n_special_dishes){
         printf("Restaurant name: %s",r[mid1].restaurant_name);
         printf("Dish: %s",r[mid1].special_items[i].sfood_item);
         printf("Price is %d\n",r[mid1].special_items[i].sprice);
         printf("Address: %s", r[mid1].ad.area);
        i++;
         printf("\n");
    }
    while(j<r[mid2].n_special_dishes){
         printf("Restaurant name: %s",r[mid2].restaurant_name);
         printf("Dish: %s",r[mid2].special_items[j].sfood_item);
         printf("Price is %d\n",r[mid2].special_items[j].sprice);
         printf("Address: %s", r[mid2].ad.area);
        j++;
         printf("\n");
    }
    
    i=0;
    j=0;
    
     printf("Unique Special Item of the day are as follows:\n");
        while (i < r[mid1].n_special_dishes_day && j < r[mid2].n_special_dishes_day) {
        int cmp = strcmp(r[mid1].special_items_day[i].sdfood_item, r[mid2].special_items_day[j].sdfood_item);
        if (cmp == 0) {
            i++;
            j++;
        } 
        else if (cmp < 0) {
             printf("Restaurant name: %s",r[mid1].restaurant_name);
            printf("Dish: %s",r[mid1].special_items_day[i].sdfood_item);
            printf("Price is %d\n",r[mid1].special_items_day[i].sdprice);
            printf("Address: %s", r[mid1].ad.area);
            i++;
             printf("\n");
        } 
        else {
            printf("Restaurant name: %s",r[mid2].restaurant_name);
            printf("Dish: %s",r[mid2].special_items_day[j].sdfood_item);
           printf("Price is %d\n",r[mid2].special_items_day[j].sdprice);
           printf("Address: %s", r[mid2].ad.area);
            j++;
             printf("\n");
        }
    }
    while(i<r[mid1].n_special_dishes_day){
         printf("Restaurant name: %s",r[mid1].restaurant_name);
         printf("Dish: %s",r[mid1].special_items_day[i].sdfood_item);
         printf("Price is %d\n",r[mid1].special_items_day[i].sdprice);
         printf("Address: %s", r[mid1].ad.area);
        i++;
         printf("\n");
    }
    while(j<r[mid2].n_special_dishes_day){
         printf("Restaurant name: %s",r[mid2].restaurant_name);
         printf("Dish: %s",r[mid2].special_items_day[j].sdfood_item);
         printf("Price is %d\n",r[mid2].special_items_day[j].sdprice);
         printf("Address: %s", r[mid2].ad.area);
        j++;
         printf("\n");
    }
  }

}
//It shows all the features to the user/
void user(struct list_restaurant r[],int n){
    int choice;
    static int k=0;
    char ans='y';
    do{
        printf("Enter your choice 1-9\n");
        printf("1: Getting minimum time for delivery of a food item:\n");
        printf("2: Getting Item Availability in a Restaurant:\n");
        printf("3:Placing An Order\n");
        printf("4: Generic Food List in Sorted Order:\n");
        printf("5:Food Items Available in Area in Sorted Order:\n");
        printf("6: Special Items List in Sorted Order:\n");
        printf("7: Special Items of the Day List in Sorted Order:\n");
        printf("8:Common Food Items in 2 Restaurants:\n");
        printf("9:Unique Food Items in Restaurant List:\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            getMinTime(r,n);
        }
        else if(choice==2)
        {
             getItemAvailability(r,n);
        }
        else if(choice==3)
        {
             PlaceOrder(r,n,k);
             k++;
        }
        else if(choice==4)
        {
            getItemListInSortedOrder(r,n);
        }
        else if(choice==5)
        {
            getItemListInAreaSortedOrder(r,n);
        }
        else if(choice==6)
        {
            getAllSpecialItemListinSortedOrder(r,n);
        }
        else if(choice==7)
        {
            getItemofDayListinSortedOrder(r,n) ;
        }
        else if(choice==8)
        {
            getCommonItem(r,n);
        }
        else if(choice==9)
        {
           getAllUniqueItem(r,n);
        }
        printf("Want to access more function? [y/n]");
        scanf(" %c",&ans);
    }
    while(ans=='y');
    
}
//admin stores the restaurant data/
void admin() {
    struct list_restaurant r[10];
    strcpy(r[0].restaurant_name,"anna idli\n");
    strcpy(r[1].restaurant_name,"bombay chat center\n");
    strcpy(r[2].restaurant_name,"banaras chat house\n");
    strcpy(r[3].restaurant_name,"fuel station\n");
    strcpy(r[4].restaurant_name,"haldiram\n");
    strcpy(r[5].restaurant_name,"indian soup factory\n");
    strcpy(r[6].restaurant_name,"nanking\n");
    strcpy(r[7].restaurant_name,"shreenath\n");
    strcpy(r[8].restaurant_name,"taco bell\n");
    strcpy(r[9].restaurant_name,"tanjore\n");
    
    strcpy(r[0].ad.street,"house no 54\n");
    strcpy(r[0].ad.area,"laxminagar\n");

    strcpy(r[1].ad.street,"deendayal nagar\n");
    strcpy(r[1].ad.area,"pratap nagar\n");
    
    strcpy(r[2].ad.street,"somalwada\n");
    strcpy(r[2].ad.area,"manish nagar\n");
    
    strcpy(r[3].ad.street,"shankar nagar\n");
    strcpy(r[3].ad.area,"bajaj nagar\n");
    
    strcpy(r[4].ad.street,"unthkhana road\n");
    strcpy(r[4].ad.area,"ayodhya nagar\n");
    
    strcpy(r[5].ad.street,"ashok nagar\n");
    strcpy(r[5].ad.area,"ranchi\n");
    
    strcpy(r[6].ad.street,"fh 56\n");
    strcpy(r[6].ad.area,"civil lines\n");
    
    strcpy(r[7].ad.street,"h-56\n");
    strcpy(r[7].ad.area,"bajaj nagar\n");
    
    strcpy(r[8].ad.street,"f-89\n");
    strcpy(r[8].ad.area,"dhantoli\n");
    
    strcpy(r[9].ad.street,"y-10\n");
    strcpy(r[9].ad.area,"bajaj nagar\n");
    
    strcpy(r[0].generic_foods[0].food_item,"idli wada\n");
    r[0].generic_foods[0].price=110;
    r[0].generic_foods[0].service_time=30;
    
    strcpy(r[0].generic_foods[1].food_item,"loni idli\n");
    r[0].generic_foods[1].price=80;
    r[0].generic_foods[1].service_time=25;
    
    strcpy(r[0].generic_foods[2].food_item,"masala dosa\n");
    r[0].generic_foods[2].price=150;
    r[0].generic_foods[2].service_time=25;
    
    strcpy(r[0].generic_foods[3].food_item,"plain dosa\n");
    r[0].generic_foods[3].price=130;
    r[0].generic_foods[3].service_time=20;
    
    strcpy(r[0].generic_foods[4].food_item,"tomato uttapam\n");
    r[0].generic_foods[4].price=150;
    r[0].generic_foods[4].service_time=25;
    
    r[0].n_gen_dishes=5;
    
    strcpy(r[1].generic_foods[0].food_item,"bhelpuri\n");
    r[1].generic_foods[0].price=90;
    r[1].generic_foods[0].service_time=25;
    
    strcpy(r[1].generic_foods[1].food_item,"sev puri\n");
    r[1].generic_foods[1].price=70;
    r[1].generic_foods[1].service_time=25;
    
    strcpy(r[1].generic_foods[2].food_item,"dahi puri\n");
    r[1].generic_foods[2].price=50;
    r[1].generic_foods[2].service_time=55;
    
    strcpy(r[1].generic_foods[3].food_item,"pani puri\n");
    r[1].generic_foods[3].price=30;
    r[1].generic_foods[3].service_time=20;
    
     r[1].n_gen_dishes=4;
     
    strcpy(r[2].generic_foods[0].food_item,"bhelpuri\n");
    r[2].generic_foods[0].price=80;
    r[2].generic_foods[0].service_time=25;
    
    strcpy(r[2].generic_foods[1].food_item,"sevpuri\n");
    r[2].generic_foods[1].price=60;
    r[2].generic_foods[1].service_time=25;
    
    strcpy(r[2].generic_foods[2].food_item,"dahipuri\n");
    r[2].generic_foods[2].price=70;
    r[2].generic_foods[2].service_time=55;
    
    strcpy(r[2].generic_foods[3].food_item,"panipuri\n");
    r[2].generic_foods[3].price=40;
    r[2].generic_foods[3].service_time=20;
    
     r[2].n_gen_dishes=4;
    
    strcpy(r[3].generic_foods[0].food_item,"schezwan rice\n");
    r[3].generic_foods[0].price=159;
    r[3].generic_foods[0].service_time=30;
    
    strcpy(r[3].generic_foods[1].food_item,"mac n cheese\n");
    r[3].generic_foods[1].price=205;
    r[3].generic_foods[1].service_time=35;
    
    strcpy(r[3].generic_foods[2].food_item,"veggie burger\n");
    r[3].generic_foods[2].price=50;
    r[3].generic_foods[2].service_time=45;
    
    strcpy(r[3].generic_foods[3].food_item,"nachos\n");
    r[3].generic_foods[3].price=100;
    r[3].generic_foods[3].service_time=40;
    
    strcpy(r[3].generic_foods[4].food_item,"crispy veg\n");
    r[3].generic_foods[4].price=50;
    r[3].generic_foods[4].service_time=55;
    
    r[3].n_gen_dishes=5;
    
    strcpy(r[4].generic_foods[0].food_item,"kadhai paneer\n");
    r[4].generic_foods[0].price=319;
    r[4].generic_foods[0].service_time=45;
    
    strcpy(r[4].generic_foods[1].food_item,"palak paneer\n");
    r[4].generic_foods[1].price=205;
    r[4].generic_foods[1].service_time=35;
    
    strcpy(r[4].generic_foods[2].food_item,"naan\n");
    r[4].generic_foods[2].price=150;
    r[4].generic_foods[2].service_time=45;
    
    strcpy(r[4].generic_foods[3].food_item,"daal tadka\n");
    r[4].generic_foods[3].price=80;
    r[4].generic_foods[3].service_time=50;
    
    r[4].n_gen_dishes=4;
    
    strcpy(r[5].generic_foods[0].food_item,"manchow soup\n");
    r[5].generic_foods[0].price=70;
    r[5].generic_foods[0].service_time=10;
    
    strcpy(r[5].generic_foods[1].food_item,"tomato soup\n");
    r[5].generic_foods[1].price=75;
    r[5].generic_foods[1].service_time=35;
    
    r[5].n_gen_dishes=2;
    
    strcpy(r[6].generic_foods[0].food_item,"schezwan rice\n");
    r[6].generic_foods[0].price=225;
    r[6].generic_foods[0].service_time=45;
    
    strcpy(r[6].generic_foods[1].food_item,"manchow soup\n");
    r[6].generic_foods[1].price=205;
    r[6].generic_foods[1].service_time=35;
    
    strcpy(r[6].generic_foods[2].food_item,"tomato soup\n");
    r[6].generic_foods[2].price=50;
    r[6].generic_foods[2].service_time=45;
    
    strcpy(r[6].generic_foods[3].food_item,"spring roll\n");
    r[6].generic_foods[3].price=100;
    r[6].generic_foods[3].service_time=40;
    
    r[6].n_gen_dishes=4;
    
    
    strcpy(r[7].generic_foods[0].food_item,"pav bhaji\n");
    r[7].generic_foods[0].price=100;
    r[7].generic_foods[0].service_time=45;
    
    strcpy(r[7].generic_foods[1].food_item,"pulav\n");
    r[7].generic_foods[1].price=105;
    r[7].generic_foods[1].service_time=25;
    
    strcpy(r[7].generic_foods[2].food_item,"pav\n");
    r[7].generic_foods[2].price=20;
    r[7].generic_foods[2].service_time=5;
    
    r[7].n_gen_dishes=3;
    
    
    strcpy(r[8].generic_foods[0].food_item,"nacho\n");
    r[8].generic_foods[0].price=125;
    r[8].generic_foods[0].service_time=45;
    
    strcpy(r[8].generic_foods[1].food_item,"manchow soup\n");
    r[8].generic_foods[1].price=205;
    r[8].generic_foods[1].service_time=35;
    
    strcpy(r[8].generic_foods[2].food_item,"pinto bean taco\n");
    r[8].generic_foods[2].price=50;
    r[8].generic_foods[2].service_time=45;
    
    strcpy(r[8].generic_foods[3].food_item,"burrito roll\n");
    r[8].generic_foods[3].price=100;
    r[8].generic_foods[3].service_time=40;
    
    r[8].n_gen_dishes=4;

     strcpy(r[9].generic_foods[0].food_item,"palak paneer\n");
    r[9].generic_foods[0].price=100;
    r[9].generic_foods[0].service_time=20;
    
    strcpy(r[9].generic_foods[1].food_item,"loni idli\n");
    r[9].generic_foods[1].price=50;
    r[9].generic_foods[1].service_time=25;
    
    strcpy(r[9].generic_foods[2].food_item,"naan\n");
    r[9].generic_foods[2].price=150;
    r[9].generic_foods[2].service_time=25;
    
    strcpy(r[9].generic_foods[3].food_item,"plain dosa\n");
    r[9].generic_foods[3].price=100;
    r[9].generic_foods[3].service_time=20;
    
    strcpy(r[9].generic_foods[4].food_item,"jeera rice\n");
    r[9].generic_foods[4].price=150;
    r[9].generic_foods[4].service_time=55;
    
    r[9].n_gen_dishes=5;
    
    strcpy(r[0].special_items[0].sfood_item,"curd rice\n");
    r[0].special_items[0].sprice=150;
    r[0].special_items[0].s_service_time=20;
    
    strcpy(r[0].special_items[1].sfood_item,"appe\n");
    r[0].special_items[1].sprice=130;
    r[0].special_items[1].s_service_time=25;
    
    strcpy(r[0].special_items[2].sfood_item,"mysore masala dosa\n");
    r[0].special_items[2].sprice=195;
    r[0].special_items[2].s_service_time=30;
    
    strcpy(r[0].special_items[3].sfood_item,"mysore plain dosa\n");
    r[0].special_items[3].sprice=175;
    r[0].special_items[3].s_service_time=35;
    
    r[0].n_special_dishes=4;
   
    strcpy(r[1].special_items[0].sfood_item,"cheese bhel\n");
    r[1].special_items[0].sprice=105;
    r[1].special_items[0].s_service_time=20;
    
    strcpy(r[1].special_items[1].sfood_item,"papdi chat\n");
    r[1].special_items[1].sprice=50;
    r[1].special_items[1].s_service_time=25;
    
    strcpy(r[1].special_items[2].sfood_item,"mysore masala dosa\n");
    r[1].special_items[2].sprice=195;
    r[1].special_items[2].s_service_time=30;
    
    strcpy(r[1].special_items[3].sfood_item,"faluda chat\n");
    r[1].special_items[3].sprice=105;
    r[1].special_items[3].s_service_time=35;
    
    r[1].n_special_dishes=4;
    
    strcpy(r[2].special_items[0].sfood_item,"bahubali chat\n");
    r[2].special_items[0].sprice=55;
    r[2].special_items[0].s_service_time=30;
    
    strcpy(r[2].special_items[1].sfood_item,"katori chat\n");
    r[2].special_items[1].sprice=135;
    r[2].special_items[1].s_service_time=25;
    
    strcpy(r[2].special_items[2].sfood_item,"khasta chat\n");
    r[2].special_items[2].sprice=55;
    r[2].special_items[2].s_service_time=40;
    
    r[2].n_special_dishes=3;
    
     
    strcpy(r[3].special_items[0].sfood_item,"chilly mushroom\n");
    r[3].special_items[0].sprice=45;
    r[3].special_items[0].s_service_time=40;
    
    strcpy(r[3].special_items[1].sfood_item,"paneer\n");
    r[3].special_items[1].sprice=60;
    r[3].special_items[1].s_service_time=45;
    
    r[3].n_special_dishes=2; 
    
    strcpy(r[4].special_items[0].sfood_item,"shahi raj kachori\n");
    r[4].special_items[0].sprice=55;
    r[4].special_items[0].s_service_time=30;
    
    strcpy(r[4].special_items[1].sfood_item,"choley bhature\n");
    r[4].special_items[1].sprice=135;
    r[4].special_items[1].s_service_time=25;
    
    strcpy(r[4].special_items[2].sfood_item,"special thali\n");
    r[4].special_items[2].sprice=255;
    r[4].special_items[2].s_service_time=40;
    
    r[4].n_special_dishes=3;
    
    strcpy(r[5].special_items[0].sfood_item,"mixed vegetable soup\n");
    r[5].special_items[0].sprice=60;
    r[5].special_items[0].s_service_time=20;
    
    strcpy(r[5].special_items[1].sfood_item,"tadka soup\n");
    r[5].special_items[1].sprice=45;
    r[5].special_items[1].s_service_time=30;
    
   r[5].n_special_dishes=2;
    
    strcpy(r[6].special_items[0].sfood_item,"fung chang choi\n");
    r[6].special_items[0].sprice=75;
    r[6].special_items[0].s_service_time=35;
    
    strcpy(r[6].special_items[1].sfood_item,"paneer\n");
    r[6].special_items[1].sprice=35;
    r[6].special_items[1].s_service_time=65;
    
    strcpy(r[6].special_items[2].sfood_item,"pasta\n");
    r[6].special_items[2].sprice=25;
    r[6].special_items[2].s_service_time=70;
    
    r[6].n_special_dishes=3;
    
    strcpy(r[7].special_items[0].sfood_item,"pista\n");
    r[7].special_items[0].sprice=75;
    r[7].special_items[0].s_service_time=35;
    
    strcpy(r[7].special_items[1].sfood_item,"roti\n");
    r[7].special_items[1].sprice=35;
    r[7].special_items[1].s_service_time=65;
    
    
    r[7].n_special_dishes=2;
    
    strcpy(r[8].special_items[0].sfood_item,"quesadilla\n");
    r[8].special_items[0].sprice=75;
    r[8].special_items[0].s_service_time=35;
    
    strcpy(r[8].special_items[1].sfood_item,"churro bombs\n");
    r[8].special_items[1].sprice=35;
    r[8].special_items[1].s_service_time=65;
    
    strcpy(r[8].special_items[2].sfood_item,"cheese max bombs\n");
    r[8].special_items[2].sprice=25;
    r[8].special_items[2].s_service_time=70;
    
    r[8].n_special_dishes=3;
    
    strcpy(r[9].special_items[0].sfood_item,"paniyaram\n");
    r[9].special_items[0].sprice=105;
    r[9].special_items[0].s_service_time=55;
    
    strcpy(r[9].special_items[1].sfood_item,"lemon rice\n");
    r[9].special_items[1].sprice=55;
    r[9].special_items[1].s_service_time=85;
    
    strcpy(r[9].special_items[2].sfood_item,"biryani\n");
    r[9].special_items[2].sprice=125;
    r[9].special_items[2].s_service_time=90;
    
    r[9].n_special_dishes=3;
    
    strcpy(r[0].special_items_day[0].sdfood_item,"paper masala dosa\n");
    r[0].special_items_day[0].sdprice=210;
    r[0].special_items_day[0].sd_service_time=20;
    
    strcpy(r[0].special_items_day[1].sdfood_item,"amarkhand\n");
    r[0].special_items_day[1].sdprice=120;
    r[0].special_items_day[1].sd_service_time=15;
    
    strcpy(r[0].special_items_day[2].sdfood_item,"filter kappi\n");
    r[0].special_items_day[2].sdprice=60;
    r[0].special_items_day[2].sd_service_time=20;
    
    r[0].n_special_dishes_day=3;
    
    strcpy(r[1].special_items_day[0].sdfood_item,"khasta chat\n");
    r[1].special_items_day[0].sdprice=120;
    r[1].special_items_day[0].sd_service_time=25;
    
    strcpy(r[1].special_items_day[1].sdfood_item,"katori chat\n");
    r[1].special_items_day[1].sdprice=100;
    r[1].special_items_day[1].sd_service_time=20;
    
    strcpy(r[1].special_items_day[2].sdfood_item,"chola patties\n");
    r[1].special_items_day[2].sdprice=95;
    r[1].special_items_day[2].sd_service_time=30;
    
    r[1].n_special_dishes_day=3;
    
    strcpy(r[2].special_items_day[0].sdfood_item,"chilly mushroom\n");
    r[2].special_items_day[0].sdprice=150;
    r[2].special_items_day[0].sd_service_time=25;
    
    strcpy(r[2].special_items_day[1].sdfood_item,"paneer\n");
    r[2].special_items_day[1].sdprice=179;
    r[2].special_items_day[1].sd_service_time=40;
    
    r[2].n_special_dishes_day=2;
    
    strcpy(r[3].special_items_day[0].sdfood_item,"triple rice\n");
    r[3].special_items_day[0].sdprice=90;
    r[3].special_items_day[0].sd_service_time=25;
    
    strcpy(r[3].special_items_day[1].sdfood_item,"kiwi mojito\n");
    r[3].special_items_day[1].sdprice=100;
    r[3].special_items_day[1].sd_service_time=40;
    
    r[3].n_special_dishes_day=2;
    
    strcpy(r[4].special_items_day[0].sdfood_item,"paneer tikka kathi roll\n");
    r[4].special_items_day[0].sdprice=60;
    r[4].special_items_day[0].sd_service_time=55;
    
    strcpy(r[4].special_items_day[1].sdfood_item,"pav bhaji\n");
    r[4].special_items_day[1].sdprice=120;
    r[4].special_items_day[1].sd_service_time=50;
    
    r[4].n_special_dishes_day=2;
    
    strcpy(r[5].special_items_day[0].sdfood_item,"lemon coriander soup\n");
    r[5].special_items_day[0].sdprice=100;
    r[5].special_items_day[0].sd_service_time=20;
    
    strcpy(r[5].special_items_day[1].sdfood_item,"sea food coriander soup\n");
    r[5].special_items_day[1].sdprice=180;
    r[5].special_items_day[1].sd_service_time=30;
    
    r[5].n_special_dishes_day=2;
    
    strcpy(r[6].special_items_day[0].sdfood_item,"ice tea\n");
    r[6].special_items_day[0].sdprice=80;
    r[6].special_items_day[0].sd_service_time=20;
    
    strcpy(r[6].special_items_day[1].sdfood_item,"veg thai curry\n");
    r[6].special_items_day[1].sdprice=100;
    r[6].special_items_day[1].sd_service_time=30;
    
    r[6].n_special_dishes_day=2; 
    
    strcpy(r[7].special_items_day[0].sdfood_item,"tomato masala pav\n");
    r[7].special_items_day[0].sdprice=55;
    r[7].special_items_day[0].sd_service_time=20;
    
    strcpy(r[7].special_items_day[1].sdfood_item,"pav bhaji\n");
    r[7].special_items_day[1].sdprice=130;
    r[7].special_items_day[1].sd_service_time=20;
    
    r[7].n_special_dishes_day=2;
    
    strcpy(r[7].special_items_day[0].sdfood_item,"tomato masala pav\n");
    r[7].special_items_day[0].sdprice=55;
    r[7].special_items_day[0].sd_service_time=20;
    
    strcpy(r[7].special_items_day[1].sdfood_item,"pav bhaji\n");
    r[7].special_items_day[1].sdprice=130;
    r[7].special_items_day[1].sd_service_time=20;
    
    r[7].n_special_dishes_day=2;
    
    strcpy(r[8].special_items_day[0].sdfood_item,"makhni paneer taco\n");
    r[8].special_items_day[0].sdprice=155;
    r[8].special_items_day[0].sd_service_time=20;
    
    strcpy(r[8].special_items_day[1].sdfood_item,"chocolate\n");
    r[8].special_items_day[1].sdprice=150;
    r[8].special_items_day[1].sd_service_time=20;
    
    r[8].n_special_dishes_day=2;
    
    strcpy(r[9].special_items_day[0].sdfood_item,"sheera\n");
    r[9].special_items_day[0].sdprice=110;
    r[9].special_items_day[0].sd_service_time=30;
    
    strcpy(r[9].special_items_day[1].sdfood_item,"paneer\n");
    r[9].special_items_day[1].sdprice=40;
    r[9].special_items_day[1].sd_service_time=20;
    
    r[9].n_special_dishes_day=2;
    
SortRestaurant(r,10);
user(r,10);
}


int main(){

    printf("Welcome to DISH DASH!!");
    printf("\nPlease enter the password: \n");   //ABC@123 IS THE PASSWORD/
    bool a=isvalid();
         if(a){
             printf("Welcome user!!");
             admin(); 
         }

    
    printf("HAVE A NICE DAY :)");
return 0;

}