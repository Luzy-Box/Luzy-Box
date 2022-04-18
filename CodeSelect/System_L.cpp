#include "System_L.h"

System_L::System_L()
{
	user = new Login;
}

System_L::~System_L()
{
	delete user;
}
