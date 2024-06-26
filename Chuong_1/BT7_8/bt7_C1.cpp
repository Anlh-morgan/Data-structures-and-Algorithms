#include <iostream>
#include <map>          // save the schedule of the train
#include <string>
#include <vector>       // save the train number
#include <algorithm>    // find the train number in the vector


// the train station
class TrainStation {
    // create a schedule for the train with the train number, time, and station
    private:
        /**
         * @note: the schedule of the train is saved in the map
         */
        // <train_number, <time, station>>
        std::map<std::string, std::map<std::string, std::string>> schedule; 



    // create a data schedule for the train
    public:
        /**
         * @note: the schedule of the train
         */
        TrainStation() {
            schedule["S2"]={{"SAI GON","21:00"}, {"MUONG MAN","NONE"}, {"THAP CHAM","NONE"}, {"NHA TRANG","04:10"},
                            {"TUY HOA","NONE"}, {"DIEU TRI","08:12"}, {"QUANG NGAI","NONE"}, {"TAM KY","NONE"},
                            {"DA NANG","13:27"}, {"HUE","16:21"}, {"DONG HA","NONE"}, {"DONG HOI","19:15"},
                            {"VINH","23:21"}, {"THANH HOA","NONE"}, {"NINH BINH","NONE"}, {"NAM DINH","NONE"},
                            {"PHU LY","NONE"}, {"HA NOI","05:00"}};
                        
            schedule["S4"]={{"SAI GON","21:50"}, {"MUONG MAN","02:10"}, {"THAP CHAM","05:01"}, {"NHA TRANG","06:47"},
                            {"TUY HOA","09:43"}, {"DIEU TRI","11:49"}, {"QUANG NGAI","15:41"}, {"TAM KY","NONE"},
                            {"DA NANG","19:04"}, {"HUE","22:42"}, {"DONG HA","00:14"}, {"DONG HOI","02:27"},
                            {"VINH","07:45"}, {"THANH HOA","10:44"}, {"NINH BINH","12:04"}, {"NAM DINH","12:37"},
                            {"PHU LY","13:23"}, {"HA NOI","14:40"}};
            
            schedule["S6"]={{"SAI GON","11:10"}, {"MUONG MAN","15:21"}, {"THAP CHAM","18:06"}, {"NHA TRANG","20:00"},
                            {"TUY HOA","23:09"}, {"DIEU TRI","01:20"}, {"QUANG NGAI","04:55"}, {"TAM KY","06:11"},
                            {"DA NANG","08:29"}, {"HUE","12:29"}, {"DONG HA","13:52"}, {"DONG HOI","15:52"},
                            {"VINH","21:00"}, {"THANH HOA","00:01"}, {"NINH BINH","01:28"}, {"NAM DINH","02:01"},
                            {"PHU LY","02:42"}, {"HA NOI","04:00"}};

            schedule["S8"]={{"SAI GON","15:40"}, {"MUONG MAN","19:53"}, {"THAP CHAM","22:47"}, {"NHA TRANG","00:47"},
                            {"TUY HOA","03:39"}, {"DIEU TRI","05:46"}, {"QUANG NGAI","09:24"}, {"TAM KY","10:39"},
                            {"DA NANG","12:20"}, {"HUE","15:47"}, {"DONG HA","17:12"}, {"DONG HOI","19:46"},
                            {"VINH","01:08"}, {"THANH HOA","04:33"}, {"NINH BINH","05:54"}, {"NAM DINH","06:26"},
                            {"PHU LY","07:08"}, {"HA NOI","08:30"}};

            schedule["S10"]={{"SAI GON","10:00"}, {"MUONG MAN","14:07"}, {"THAP CHAM","16:43"}, {"NHA TRANG","18:50"},
                            {"TUY HOA","21:53"}, {"DIEU TRI","00:00"}, {"QUANG NGAI","03:24"}, {"TAM KY","04:38"},
                            {"DA NANG","06:19"}, {"HUE","11:12"}, {"DONG HA","12:42"}, {"DONG HOI","14:41"},
                            {"VINH","20:12"}, {"THANH HOA","23:09"}, {"NINH BINH","00:31"}, {"NAM DINH","01:24"},
                            {"PHU LY","02:02"}, {"HA NOI","03:15"}};

            schedule["S12"]={{"SAI GON","12:30"}, {"MUONG MAN","16:41"}, {"THAP CHAM","19:19"}, {"NHA TRANG","21:10"},
                            {"TUY HOA","00:19"}, {"DIEU TRI","02:30"}, {"QUANG NGAI","05:55"}, {"TAM KY","07:10"},
                            {"DA NANG","09:26"}, {"HUE","14:32"}, {"DONG HA","16:05"}, {"DONG HOI","17:59"},
                            {"VINH","23:50"}, {"THANH HOA","03:33"}, {"NINH BINH","04:50"}, {"NAM DINH","05:22"},
                            {"PHU LY","06:00"}, {"HA NOI","07:10"}};

            schedule["S14"]={{"SAI GON","17:00"}, {"MUONG MAN","21:04"}, {"THAP CHAM","00:08"}, {"NHA TRANG","01:57"},
                            {"TUY HOA","05:11"}, {"DIEU TRI","07:09"}, {"QUANG NGAI","11:21"}, {"TAM KY","12:40"},
                            {"DA NANG","14:41"}, {"HUE","18:13"}, {"DONG HA","19:38"}, {"DONG HOI","21:38"},
                            {"VINH","02:59"}, {"THANH HOA","06:39"}, {"NINH BINH","07:57"}, {"NAM DINH","08:29"},
                            {"PHU LY","09:09"}, {"HA NOI","10:25"}};

            schedule["S16"]={{"SAI GON","20:00"}, {"MUONG MAN","01:15"}, {"THAP CHAM","04:05"}, {"NHA TRANG","05:42"},
                            {"TUY HOA","08:36"}, {"DIEU TRI","10:42"}, {"QUANG NGAI","14:35"}, {"TAM KY","16:08"},
                            {"DA NANG","17:43"}, {"HUE","21:14"}, {"DONG HA","22:39"}, {"DONG HOI","00:52"},
                            {"VINH","07:07"}, {"THANH HOA","09:59"}, {"NINH BINH","11:12"}, {"NAM DINH","11:44"},
                            {"PHU LY","12:23"}, {"HA NOI","13:45"}};

            schedule["S18"]={{"SAI GON","22:20"}, {"MUONG MAN","03:16"}, {"THAP CHAM","06:03"}, {"NHA TRANG","08:06"},
                            {"TUY HOA","10:50"}, {"DIEU TRI","13:00"}, {"QUANG NGAI","17:04"}, {"TAM KY","18:21"},
                            {"DA NANG","20:17"}, {"HUE","23:50"}, {"DONG HA","01:25"}, {"DONG HOI","03:28"},
                            {"VINH","09:20"}, {"THANH HOA","12:20"}, {"NINH BINH","13:51"}, {"NAM DINH","14:25"},
                            {"PHU LY","15:06"}, {"HA NOI","16:20"}};
            
            schedule["LH2"]={{"SAI GON","13:20"}, {"MUONG MAN","17:35"}, {"THAP CHAM","20:19"}, {"NHA TRANG","22:46"},
                            {"TUY HOA","02:10"}, {"DIEU TRI","04:15"}, {"QUANG NGAI","07:34"}, {"TAM KY","09:03"},
                            {"DA NANG","10:53"}, {"HUE","15:10"}, {"DONG HA","NONE"}, {"DONG HOI","NONE"},
                            {"VINH","NONE"}, {"THANH HOA","NONE"}, {"NINH BINH","NONE"}, {"NAM DINH","NONE"},
                            {"PHU LY","NONE"}, {"HA NOI","NONE"}};

            schedule["SN2"]={{"SAI GON","18:40"}, {"MUONG MAN","22:58"}, {"THAP CHAM","02:15"}, {"NHA TRANG","05:15"},
                            {"TUY HOA","NONE"}, {"DIEU TRI","NONE"}, {"QUANG NGAI","NONE"}, {"TAM KY","NONE"},
                            {"DA NANG","NONE"}, {"HUE","NONE"}, {"DONG HA","NONE"}, {"DONG HOI","NONE"},
                            {"VINH","NONE"}, {"THANH HOA","NONE"}, {"NINH BINH","NONE"}, {"NAM DINH","NONE"},
                            {"PHU LY","NONE"}, {"HA NOI","NONE"}};
        }

        // xuất ra thời gian của 1 tàu tại 1 ga nào đó
        /**
         * @param train_number: số hiệu tàu
         * @param station: ga cần tìm
         * @return: thời gian tàu đến ga đó
         * @note: nếu tàu không dừng ở ga đó thì xuất ra thông báo
         * @note: nếu tàu không tồn tại thì xuất ra thông báo
         * @note: nếu ga không tồn tại thì xuất ra thông báo 
         */
        void get_time_at_station(std::string train_number, std::string station) {
            std::map<std::string, std::string> train_schedule = schedule[train_number];
            std::map<std::string, std::string>::iterator it = train_schedule.find(station);
            if (it != train_schedule.end())
                std::cout << "The train " << train_number << " will arrive at " << station << " at " << it->second << std::endl;
            else
                std::cout << "The train " << train_number << " does not stop at " << station << std::endl;
        }

        // xuất ra giờ đến các ga của 1 tàu nào đó
        /**
         * @param train_number: số hiệu tàu
         * @note: nếu tàu không tồn tại thì xuất ra thông báo
         */
        void get_schedule(std::string train_number) {
            std::map<std::string, std::string> train_schedule = schedule[train_number];
            std::cout << "The schedule of the train " << train_number << " is: " << std::endl;
            for (std::map<std::string, std::string>::iterator it = train_schedule.begin(); it != train_schedule.end(); it++)
                std::cout << it->first << ": " << it->second << std::endl;
        }


        // xuất ra giờ các tàu đến 1 ga nào đó
        /**
         * @param station: ga cần tìm
         * @note: nếu ga không tồn tại thì xuất ra thông báo
         */
        void get_time_of_train_toStation(std::string station) {
            std::cout << "The train will arrive at " << station << " at: " << std::endl;
            for (std::map<std::string, std::map<std::string, std::string>>::iterator it = schedule.begin(); it != schedule.end(); it++) {
                std::map<std::string, std::string> train_schedule = it->second;
                std::map<std::string, std::string>::iterator it2 = train_schedule.find(station);
                if (it2 != train_schedule.end())
                    std::cout << it->first << ": " << it2->second << std::endl;
            }
        }

        // xuất ra bảng giờ tàu
        void get_all_schedule() {
            std::cout << "The schedule of the train is: " << std::endl;
            for (std::map<std::string, std::map<std::string, std::string>>::iterator it = schedule.begin(); it != schedule.end(); it++) {
                std::cout << "The schedule of the train " << it->first << " is: " << std::endl;
                for (std::map<std::string, std::string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
                    std::cout << it2->first << ": " << it2->second << std::endl;
            }
        }

};


// bai 8
/* ghi nhan them thong tin ve doan tau khi dung tai cac ga chi de tranh tau hay de cho hanh khach len/xuong */


int main() {
    TrainStation train_station;
    
    std::string in_train_number;   std::string in_station;
    std::cout << "Enter the train number: "; std::cin >> in_train_number;
    
    // nhap dau cach
    std::cout << "Enter the station: "; std::cin.ignore();
    std::getline(std::cin, in_station);



    // test get_time_at_station
    train_station.get_time_at_station(in_train_number, in_station);

    // test get_schedule
    train_station.get_schedule(in_train_number);

    // test get_time_of_train_toStation
    train_station.get_time_of_train_toStation(in_station);

    // test get_all_schedule
    train_station.get_all_schedule();


    // bai 8
/* ghi nhan them thong tin ve doan tau khi dung tai cac ga chi de tranh tau hay de cho hanh khach len/xuong */

    return 0;
}