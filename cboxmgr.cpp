#include "pch.h"
#include "cboxmgr.h"


#define ERR_PORT 3
#define ERR_PIN 8
cboxmgr::cboxmgr()
{
    for (char i = 0; i< SEGMENT_NUM; i++)
    {
        cfg_inf.segments[i].port = ERR_PORT;
        cfg_inf.segments[i].pin = ERR_PIN;
    }   
}


int cboxmgr::set_segment_port(const char sgmt_pin, const char mc_port)
{
    if (mc_port > AVR_PORTS_NUM) 
        return ERR;

    cfg_inf.segments[sgmt_pin].port = mc_port;
    return OK;
}


int cboxmgr::set_segment_pin(const char sgmt_pin, const int port_pin)
{
    release_segment_buisy_pin(sgmt_pin);

    if ((port_pin > PINS_IN_PORT_NUM) || (CB_ERR == port_pin) || EMPTY_IDX == port_pin)
    {
        return ERR;
    }     

    char j = port_pin;
    char i = 0;

    for (; i < PINS_IN_PORT_NUM; i++)
    {
        if (!(cfg_inf.buisy_pins[cfg_inf.segments[sgmt_pin].port] & (1 << i)))
            if (!(--j))
                break;
    }

    cfg_inf.buisy_pins[cfg_inf.segments[sgmt_pin].port] |= (1 << i);
    cfg_inf.segments[sgmt_pin].pin = i;

    return OK;
}

int cboxmgr::release_segment_buisy_pin(const char segment_pin)
{
    if (cfg_inf.segments[segment_pin].port < AVR_PORTS_NUM)
    {
        if (cfg_inf.segments[segment_pin].pin < SEGMENT_NUM)
        {
            cfg_inf.buisy_pins[cfg_inf.segments[segment_pin].port] &= ~(1 << cfg_inf.segments[segment_pin].pin);
            cfg_inf.segments[segment_pin].pin = PINS_IN_PORT_NUM;
            return OK;
        }
    }
    return ERR;
}

bool cboxmgr::pin_isnt_sized(const char mc_port, const char port_pin)
{
    return !(cfg_inf.buisy_pins[mc_port] & (1 << port_pin));
}

int cboxmgr::get_segm_port(char segm_index)
{
    return cfg_inf.segments[segm_index].port;
}

int cboxmgr::get_segm_pin(char segm_index)
{
    return cfg_inf.segments[segm_index].pin;
}

void cboxmgr::set_indicator_type_anode(void)
{
    cfg_inf.type = ANODE;
}

void cboxmgr::set_indicator_type_cathode(void)
{
    cfg_inf.type = CATHODE;
}

/*
int cboxmgr::save_configs()
{
    CFile Configsfile;
    CFileException cfex;
    if (!Configsfile.Open(L"segmconfigs.atm8", CFile::modeCreate | CFile::modeWrite, &cfex))
    {
        MessageBox(NULL, L"File openning is failed!", L"Error", MB_OK | MB_ICONERROR);
        return -1;
    }
    else
    {
        Configsfile.Write((char*)&cfg_inf, sizeof(config_info));
        MessageBox(NULL, L"File saved!", L"Info", MB_OK | MB_ICONINFORMATION);
    }
    Configsfile.Close();
}

int cboxmgr::load_configs()
{
    CFile Configsfile;
    CFileException cfex;
    if (!Configsfile.Open(L"segmconfigs.atm8", CFile::modeRead, &cfex))
    {
        return -1;
    }
    else
    {
        Configsfile.Read((char*)&cfg_inf, sizeof(config_info));
    }
    Configsfile.Close();
    return 0;
}

*/