#ifndef PIXIE4E_H_
#define PIXIE4E_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"

#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 7000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.7 or later is required"
#endif

class pixie4e_t : public kaitai::kstruct {

public:
    class pixie4e_header_t;
    class event_t;
    class channel_header_t;

    pixie4e_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, pixie4e_t* p__root = 0);

private:
    void _read();

public:
    ~pixie4e_t();

    class pixie4e_header_t : public kaitai::kstruct {

    public:

        pixie4e_header_t(kaitai::kstream* p__io, pixie4e_t* p__parent = 0, pixie4e_t* p__root = 0);

    private:
        void _read();

    public:
        ~pixie4e_header_t();

    private:
        uint16_t m_blk_size;
        uint16_t m_mod_num;
        uint16_t m_run_format;
        uint16_t m_chan_head_len;
        uint16_t m_coinc_pat;
        uint16_t m_coinc_win;
        uint16_t m_max_comb_event_len;
        uint16_t m_board_version;
        uint16_t m_event_length_0;
        uint16_t m_event_length_1;
        uint16_t m_event_length_2;
        uint16_t m_event_length_3;
        uint16_t m_serial_number;
        std::vector<uint16_t>* m_unused;
        pixie4e_t* m__root;
        pixie4e_t* m__parent;

    public:
        uint16_t blk_size() const { return m_blk_size; }
        uint16_t mod_num() const { return m_mod_num; }
        uint16_t run_format() const { return m_run_format; }
        uint16_t chan_head_len() const { return m_chan_head_len; }
        uint16_t coinc_pat() const { return m_coinc_pat; }
        uint16_t coinc_win() const { return m_coinc_win; }
        uint16_t max_comb_event_len() const { return m_max_comb_event_len; }
        uint16_t board_version() const { return m_board_version; }
        uint16_t event_length_0() const { return m_event_length_0; }
        uint16_t event_length_1() const { return m_event_length_1; }
        uint16_t event_length_2() const { return m_event_length_2; }
        uint16_t event_length_3() const { return m_event_length_3; }
        uint16_t serial_number() const { return m_serial_number; }
        std::vector<uint16_t>* unused() const { return m_unused; }
        pixie4e_t* _root() const { return m__root; }
        pixie4e_t* _parent() const { return m__parent; }
    };

    class event_t : public kaitai::kstruct {

    public:

        event_t(kaitai::kstream* p__io, pixie4e_t* p__parent = 0, pixie4e_t* p__root = 0);

    private:
        void _read();

    public:
        ~event_t();

    private:
        channel_header_t* m_header;
        std::vector<uint16_t>* m_data;
        pixie4e_t* m__root;
        pixie4e_t* m__parent;

    public:
        channel_header_t* header() const { return m_header; }
        std::vector<uint16_t>* data() const { return m_data; }
        pixie4e_t* _root() const { return m__root; }
        pixie4e_t* _parent() const { return m__parent; }
    };

    class channel_header_t : public kaitai::kstruct {

    public:

        channel_header_t(kaitai::kstream* p__io, pixie4e_t::event_t* p__parent = 0, pixie4e_t* p__root = 0);

    private:
        void _read();

    public:
        ~channel_header_t();

    private:
        bool f_timestamp_full;
        int32_t m_timestamp_full;

    public:
        int32_t timestamp_full();

    private:
        uint16_t m_evt_pattern;
        uint16_t m_evt_info;
        uint16_t m_num_trace_blks;
        uint16_t m_num_trace_blks_prev;
        uint16_t m_trig_time_lo;
        uint16_t m_trig_time_mi;
        uint16_t m_trig_time_hi;
        uint16_t m_trig_time_x;
        uint16_t m_energy;
        uint16_t m_chan_no;
        uint16_t m_user_psa_value;
        uint16_t m_xia_psa_value;
        std::vector<uint16_t>* m_extended_psa_values;
        std::vector<uint16_t>* m_reserved;
        pixie4e_t* m__root;
        pixie4e_t::event_t* m__parent;

    public:
        uint16_t evt_pattern() const { return m_evt_pattern; }
        uint16_t evt_info() const { return m_evt_info; }
        uint16_t num_trace_blks() const { return m_num_trace_blks; }
        uint16_t num_trace_blks_prev() const { return m_num_trace_blks_prev; }
        uint16_t trig_time_lo() const { return m_trig_time_lo; }
        uint16_t trig_time_mi() const { return m_trig_time_mi; }
        uint16_t trig_time_hi() const { return m_trig_time_hi; }
        uint16_t trig_time_x() const { return m_trig_time_x; }
        uint16_t energy() const { return m_energy; }
        uint16_t chan_no() const { return m_chan_no; }
        uint16_t user_psa_value() const { return m_user_psa_value; }
        uint16_t xia_psa_value() const { return m_xia_psa_value; }
        std::vector<uint16_t>* extended_psa_values() const { return m_extended_psa_values; }
        std::vector<uint16_t>* reserved() const { return m_reserved; }
        pixie4e_t* _root() const { return m__root; }
        pixie4e_t::event_t* _parent() const { return m__parent; }
    };

private:
    pixie4e_header_t* m_file_header;
    std::vector<event_t*>* m_events;
    pixie4e_t* m__root;
    kaitai::kstruct* m__parent;

public:
    pixie4e_header_t* file_header() const { return m_file_header; }
    std::vector<event_t*>* events() const { return m_events; }
    pixie4e_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // PIXIE4E_H_
