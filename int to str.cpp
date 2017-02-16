递归写法
void intor(int in, string& add)
{
	if (in < 10)
	{
		char temp = in + '0';
		add +=temp;
		//为10以内后
	}
	else
	{
		intor(in / 10, add);
		add += (in % 10 + '0');//根据执行的顺序，自动取模
    }
}
string inttostr(int in)
{
	string temp="";
	if (in < 0)//用于负数的时候
  {
		temp = "-";
		in *= (-1);
	}

	intor(in, temp);

	return temp;



}
