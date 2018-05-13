module Chat {
    interface Room;
    interface RoomFactory;

    exception UserAlreadyExists {};
    exception RoomAlreadyExists {};
    exception NoRoomsAvailable {};
    exception NoRoomFactoryAvailable {};
    exception RoomNotExists {};
    exception UserNotExists {};
    exception AuthenticationFailed {};

    interface User {
      void SendMessage(Room* where, User* who, string message);
      void SendPrivateMessage(User* who, string message);
      string getName();
    };

    sequence<Room*> RoomList;
    sequence<RoomFactory*> RoomFactoryList;

    interface Server {
      Room* CreateRoom(string name);
      RoomList getRooms();
      Room* FindRoom(string name);
      void RegisterUser(string name, string password) throws UserAlreadyExists;
      void ChangePassword(User* user, string oldpassword, string newpassword);
      void getPassword(string user);
      void RegisterRoomFactory(RoomFactory* factory);
      void UnregisterRoomFactory(RoomFactory* factory);
      bool auth(string name, string password);
    };

    sequence<User*> UserList;

    interface Room {
      string getName();
      UserList getUsers();
      void AddUser(User* who, string password);
      void SendMessage(User* who, string message, string passwd);
      void Destroy();
      void LeaveRoom(User* who, string passwd);
    };

    interface RoomFactory
    {
       Room* createRoom(string name);
       RoomList getRooms();
    };
};
