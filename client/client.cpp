#include <boost/asio.hpp>
#include <iostream>
using namespace boost::asio;
using namespace std;


int main()
try
{
	typedef ip::address			address_type;  //简化类型定义
	typedef ip::tcp::endpoint	endpoint_type;
	typedef ip::tcp::socket		socket_type;

	cout << "client start." << endl;
	io_service io;												//io_service对象
	socket_type sock(io);
	endpoint_type ep(										//创建连接端点
		address_type::from_string("127.0.0.1"), 6688);
	
	sock.connect(ep);										//socket连接到端点
	cout << sock.available() << endl;				//获取可读取的字节数

	vector<char> str(sock.available() + 1, 0);	//定义一个vector缓冲区
	sock.receive(buffer(str));							//使用buffer()包装缓冲区的接收数据
	cout << "receive from" << sock.remote_endpoint().address();
	cout << str[0] << endl;							//输出接收到的字符串

	//两种读取方式
	//vector<char> str(5, 0);								//缓冲区长度5
	//error_code ec;											//错误码
	//for (;;)
	//{
	//	sock.read_some(buffer(str), ec);
	//	if (ec)
	//	{	break;	}
	//	cout << &str[0];
	//}
}
catch (const std::exception& e)						//捕获可能发生的异常
{
	cout << e.what() << endl;
}