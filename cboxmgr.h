#pragma once

#include <map>
#include "ConfiguratorAppTypes.h"
using namespace std;
class cboxmgr
{
private:
	config_info cfg_inf;

public:
	cboxmgr();

	int save_configs();
	int load_configs();

	void set_indicator_type_anode(void);
	void set_indicator_type_cathode(void);
	int get_segm_port(char segm_index);
	int get_segm_pin(char segm_index);
	bool pin_isnt_sized(const char mc_port, const char port_pin);
	int release_segment_buisy_pin(const char segment_pin);
	int set_segment_port(const char segment_pin, const char mc_port);
	int set_segment_pin(const char segment_pin, const int port_pin);
	//int set_segment_pin(const char segment_pin, const char mc_port, const char port_pin);
};

