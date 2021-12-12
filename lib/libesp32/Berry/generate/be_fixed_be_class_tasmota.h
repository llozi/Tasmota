#include "be_constobj.h"

static be_define_const_map_slots(be_class_tasmota_map) {
    { be_const_key(gc, -1), be_const_closure(Tasmota_gc_closure) },
    { be_const_key(read_sensors, 7), be_const_func(l_read_sensors) },
    { be_const_key(_get_cb, -1), be_const_func(l_get_cb) },
    { be_const_key(response_append, 50), be_const_func(l_respAppend) },
    { be_const_key(try_rule, 74), be_const_closure(Tasmota_try_rule_closure) },
    { be_const_key(eth, -1), be_const_func(l_eth) },
    { be_const_key(find_key_i, -1), be_const_closure(Tasmota_find_key_i_closure) },
    { be_const_key(exec_tele, 73), be_const_closure(Tasmota_exec_tele_closure) },
    { be_const_key(remove_driver, 28), be_const_closure(Tasmota_remove_driver_closure) },
    { be_const_key(load, -1), be_const_closure(Tasmota_load_closure) },
    { be_const_key(_settings_ptr, -1), be_const_comptr(&Settings) },
    { be_const_key(cmd_res, -1), be_const_var(0) },
    { be_const_key(time_str, 43), be_const_closure(Tasmota_time_str_closure) },
    { be_const_key(set_power, -1), be_const_func(l_setpower) },
    { be_const_key(yield, 20), be_const_func(l_yield) },
    { be_const_key(set_light, -1), be_const_closure(Tasmota_set_light_closure) },
    { be_const_key(find_op, 32), be_const_closure(Tasmota_find_op_closure) },
    { be_const_key(get_power, -1), be_const_func(l_getpower) },
    { be_const_key(add_rule, -1), be_const_closure(Tasmota_add_rule_closure) },
    { be_const_key(cb_dispatch, -1), be_const_closure(Tasmota_cb_dispatch_closure) },
    { be_const_key(global, -1), be_const_var(1) },
    { be_const_key(i2c_enabled, -1), be_const_func(l_i2cenabled) },
    { be_const_key(remove_cmd, 10), be_const_closure(Tasmota_remove_cmd_closure) },
    { be_const_key(millis, 18), be_const_func(l_millis) },
    { be_const_key(publish, 69), be_const_func(l_publish) },
    { be_const_key(_drivers, -1), be_const_var(2) },
    { be_const_key(resp_cmnd, -1), be_const_func(l_respCmnd) },
    { be_const_key(time_dump, -1), be_const_func(l_time_dump) },
    { be_const_key(web_send, -1), be_const_func(l_webSend) },
    { be_const_key(hs2rgb, -1), be_const_closure(Tasmota_hs2rgb_closure) },
    { be_const_key(memory, -1), be_const_func(l_memory) },
    { be_const_key(gen_cb, 0), be_const_closure(Tasmota_gen_cb_closure) },
    { be_const_key(rtc, -1), be_const_func(l_rtc) },
    { be_const_key(get_option, -1), be_const_func(l_getoption) },
    { be_const_key(add_cmd, -1), be_const_closure(Tasmota_add_cmd_closure) },
    { be_const_key(init, -1), be_const_closure(Tasmota_init_closure) },
    { be_const_key(_timers, -1), be_const_var(3) },
    { be_const_key(_global_addr, -1), be_const_comptr(&TasmotaGlobal) },
    { be_const_key(wd, -1), be_const_var(4) },
    { be_const_key(exec_cmd, -1), be_const_closure(Tasmota_exec_cmd_closure) },
    { be_const_key(wire_scan, -1), be_const_closure(Tasmota_wire_scan_closure) },
    { be_const_key(_global_def, 61), be_const_comptr(&be_tasmota_global_struct) },
    { be_const_key(resp_cmnd_failed, 11), be_const_func(l_respCmndFailed) },
    { be_const_key(chars_in_string, -1), be_const_closure(Tasmota_chars_in_string_closure) },
    { be_const_key(web_send_decimal, -1), be_const_func(l_webSendDecimal) },
    { be_const_key(_debug_present, 4), be_const_var(5) },
    { be_const_key(cmd, -1), be_const_closure(Tasmota_cmd_closure) },
    { be_const_key(_cb, -1), be_const_var(6) },
    { be_const_key(remove_rule, -1), be_const_closure(Tasmota_remove_rule_closure) },
    { be_const_key(run_deferred, -1), be_const_closure(Tasmota_run_deferred_closure) },
    { be_const_key(strftime, -1), be_const_func(l_strftime) },
    { be_const_key(add_driver, 3), be_const_closure(Tasmota_add_driver_closure) },
    { be_const_key(kv, 60), be_const_closure(Tasmota_kv_closure) },
    { be_const_key(set_timer, 58), be_const_closure(Tasmota_set_timer_closure) },
    { be_const_key(scale_uint, -1), be_const_func(l_scaleuint) },
    { be_const_key(remove_timer, -1), be_const_closure(Tasmota_remove_timer_closure) },
    { be_const_key(settings, 49), be_const_var(7) },
    { be_const_key(arch, -1), be_const_func(l_arch) },
    { be_const_key(_ccmd, 64), be_const_var(8) },
    { be_const_key(wire1, 46), be_const_var(9) },
    { be_const_key(exec_rules, 66), be_const_closure(Tasmota_exec_rules_closure) },
    { be_const_key(strptime, -1), be_const_func(l_strptime) },
    { be_const_key(_cmd, -1), be_const_func(l_cmd) },
    { be_const_key(resp_cmnd_error, -1), be_const_func(l_respCmndError) },
    { be_const_key(time_reached, -1), be_const_func(l_timereached) },
    { be_const_key(_rules, -1), be_const_var(10) },
    { be_const_key(publish_result, -1), be_const_func(l_publish_result) },
    { be_const_key(_settings_def, -1), be_const_comptr(&be_tasmota_settings_struct) },
    { be_const_key(get_switch, -1), be_const_func(l_getswitch) },
    { be_const_key(delay, 71), be_const_func(l_delay) },
    { be_const_key(resp_cmnd_str, -1), be_const_func(l_respCmndStr) },
    { be_const_key(wifi, -1), be_const_func(l_wifi) },
    { be_const_key(save, 15), be_const_func(l_save) },
    { be_const_key(log, 37), be_const_func(l_logInfo) },
    { be_const_key(resolvecmnd, -1), be_const_func(l_resolveCmnd) },
    { be_const_key(resp_cmnd_done, -1), be_const_func(l_respCmndDone) },
    { be_const_key(get_light, 5), be_const_closure(Tasmota_get_light_closure) },
    { be_const_key(get_free_heap, -1), be_const_func(l_getFreeHeap) },
    { be_const_key(wire2, -1), be_const_var(11) },
    { be_const_key(event, 34), be_const_closure(Tasmota_event_closure) },
};

static be_define_const_map(
    be_class_tasmota_map,
    80
);

BE_EXPORT_VARIABLE be_define_const_class(
    be_class_tasmota,
    12,
    NULL,
    Tasmota
);
