五个主要的函数及其作用
  LinkList：：LinkList(string);//对算式字符串去空格然后保存 
	int LinkList：：analyze();//判断是否是正确的 算式，正确返回0，错误返回1  
	Link *LinkList：：get();//将算式储存在链表里并返回头指针 
	int LinkList：：Get(int,char,Link *head);//输入指数和未知数返回系数 
  int LinkList：：Get_coefficient(int)//输入指数返回系数
  储存是若是常数则默认未知数是空格，并将指数设为0；
