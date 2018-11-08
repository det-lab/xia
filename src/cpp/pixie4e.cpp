// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "pixie4e.h"



pixie4e_t::pixie4e_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, pixie4e_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    _read();
}

void pixie4e_t::_read() {
    m_file_header = new pixie4e_header_t(m__io, this, m__root);
    m_events = new std::vector<event_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_events->push_back(new event_t(m__io, this, m__root));
            i++;
        }
    }
}

pixie4e_t::~pixie4e_t() {
    delete m_file_header;
    for (std::vector<event_t*>::iterator it = m_events->begin(); it != m_events->end(); ++it) {
        delete *it;
    }
    delete m_events;
}

pixie4e_t::pixie4e_header_t::pixie4e_header_t(kaitai::kstream* p__io, pixie4e_t* p__parent, pixie4e_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void pixie4e_t::pixie4e_header_t::_read() {
    m_blk_size = m__io->read_u2le();
    m_mod_num = m__io->read_u2le();
    m_run_format = m__io->read_u2le();
    m_chan_head_len = m__io->read_u2le();
    m_coinc_pat = m__io->read_u2le();
    m_coinc_win = m__io->read_u2le();
    m_max_comb_event_len = m__io->read_u2le();
    m_board_version = m__io->read_u2le();
    m_event_length_0 = m__io->read_u2le();
    m_event_length_1 = m__io->read_u2le();
    m_event_length_2 = m__io->read_u2le();
    m_event_length_3 = m__io->read_u2le();
    m_serial_number = m__io->read_u2le();
    int l_unused = 19;
    m_unused = new std::vector<uint16_t>();
    m_unused->reserve(l_unused);
    for (int i = 0; i < l_unused; i++) {
        m_unused->push_back(m__io->read_u2le());
    }
}

pixie4e_t::pixie4e_header_t::~pixie4e_header_t() {
    delete m_unused;
}

pixie4e_t::event_t::event_t(kaitai::kstream* p__io, pixie4e_t* p__parent, pixie4e_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void pixie4e_t::event_t::_read() {
    m_header = new channel_header_t(m__io, this, m__root);
    int l_data = (header()->num_trace_blks() * _root()->file_header()->blk_size());
    m_data = new std::vector<uint16_t>();
    m_data->reserve(l_data);
    for (int i = 0; i < l_data; i++) {
        m_data->push_back(m__io->read_u2le());
    }
}

pixie4e_t::event_t::~event_t() {
    delete m_header;
    delete m_data;
}

pixie4e_t::channel_header_t::channel_header_t(kaitai::kstream* p__io, pixie4e_t::event_t* p__parent, pixie4e_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_timestamp_full = false;
    _read();
}

void pixie4e_t::channel_header_t::_read() {
    m_evt_pattern = m__io->read_u2le();
    m_evt_info = m__io->read_u2le();
    m_num_trace_blks = m__io->read_u2le();
    m_num_trace_blks_prev = m__io->read_u2le();
    m_trig_time_lo = m__io->read_u2le();
    m_trig_time_mi = m__io->read_u2le();
    m_trig_time_hi = m__io->read_u2le();
    m_trig_time_x = m__io->read_u2le();
    m_energy = m__io->read_u2le();
    m_chan_no = m__io->read_u2le();
    m_user_psa_value = m__io->read_u2le();
    m_xia_psa_value = m__io->read_u2le();
    int l_extended_psa_values = 4;
    m_extended_psa_values = new std::vector<uint16_t>();
    m_extended_psa_values->reserve(l_extended_psa_values);
    for (int i = 0; i < l_extended_psa_values; i++) {
        m_extended_psa_values->push_back(m__io->read_u2le());
    }
    int l_reserved = 16;
    m_reserved = new std::vector<uint16_t>();
    m_reserved->reserve(l_reserved);
    for (int i = 0; i < l_reserved; i++) {
        m_reserved->push_back(m__io->read_u2le());
    }
}

pixie4e_t::channel_header_t::~channel_header_t() {
    delete m_extended_psa_values;
    delete m_reserved;
}

int32_t pixie4e_t::channel_header_t::timestamp_full() {
    if (f_timestamp_full)
        return m_timestamp_full;
    m_timestamp_full = ((trig_time_lo() + (trig_time_mi() << 16)) + (trig_time_hi() << 32));
    f_timestamp_full = true;
    return m_timestamp_full;
}
