/* Solidification of Matter_Plugin_Sensor_Occupancy.h */
/********************************************************************\
* Generated code, don't edit                                         *
\********************************************************************/
#include "be_constobj.h"

extern const bclass be_class_Matter_Plugin_Sensor_Occupancy;

/********************************************************************
** Solidified function: <lambda>
********************************************************************/
be_local_closure(Matter_Plugin_Sensor_Occupancy__X3Clambda_X3E,   /* name */
  be_nested_proto(
    3,                          /* nstack */
    1,                          /* argc */
    0,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    0,                          /* has constants */
    NULL,                       /* no const */
    be_str_weak(_X3Clambda_X3E),
    &be_const_str_solidified,
    ( &(const binstruction[ 4]) {  /* code */
      0x60040009,  //  0000  GETGBL	R1	G9
      0x5C080000,  //  0001  MOVE	R2	R0
      0x7C040200,  //  0002  CALL	R1	1
      0x80040200,  //  0003  RET	1	R1
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: parse_configuration
********************************************************************/
be_local_closure(Matter_Plugin_Sensor_Occupancy_parse_configuration,   /* name */
  be_nested_proto(
    7,                          /* nstack */
    2,                          /* argc */
    2,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    ( &(const bvalue[ 5]) {     /* constants */
    /* K0   */  be_nested_str_weak(tasmota_switch_index),
    /* K1   */  be_nested_str_weak(find),
    /* K2   */  be_nested_str_weak(ARG),
    /* K3   */  be_const_int(1),
    /* K4   */  be_const_int(0),
    }),
    be_str_weak(parse_configuration),
    &be_const_str_solidified,
    ( &(const binstruction[12]) {  /* code */
      0x60080009,  //  0000  GETGBL	R2	G9
      0x8C0C0301,  //  0001  GETMET	R3	R1	K1
      0x88140102,  //  0002  GETMBR	R5	R0	K2
      0x58180003,  //  0003  LDCONST	R6	K3
      0x7C0C0600,  //  0004  CALL	R3	3
      0x7C080200,  //  0005  CALL	R2	1
      0x90020002,  //  0006  SETMBR	R0	K0	R2
      0x88080100,  //  0007  GETMBR	R2	R0	K0
      0x18080504,  //  0008  LE	R2	R2	K4
      0x780A0000,  //  0009  JMPF	R2	#000B
      0x90020103,  //  000A  SETMBR	R0	K0	K3
      0x80000000,  //  000B  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: read_attribute
********************************************************************/
be_local_closure(Matter_Plugin_Sensor_Occupancy_read_attribute,   /* name */
  be_nested_proto(
    10,                          /* nstack */
    3,                          /* argc */
    2,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    ( &(const bvalue[14]) {     /* constants */
    /* K0   */  be_nested_str_weak(matter),
    /* K1   */  be_nested_str_weak(TLV),
    /* K2   */  be_nested_str_weak(cluster),
    /* K3   */  be_nested_str_weak(attribute),
    /* K4   */  be_const_int(0),
    /* K5   */  be_nested_str_weak(shadow_occupancy),
    /* K6   */  be_nested_str_weak(create_TLV),
    /* K7   */  be_nested_str_weak(U1),
    /* K8   */  be_nested_str_weak(NULL),
    /* K9   */  be_const_int(1),
    /* K10  */  be_const_int(3),
    /* K11  */  be_const_int(2),
    /* K12  */  be_nested_str_weak(U4),
    /* K13  */  be_nested_str_weak(read_attribute),
    }),
    be_str_weak(read_attribute),
    &be_const_str_solidified,
    ( &(const binstruction[68]) {  /* code */
      0xB80E0000,  //  0000  GETNGBL	R3	K0
      0x880C0701,  //  0001  GETMBR	R3	R3	K1
      0x88100502,  //  0002  GETMBR	R4	R2	K2
      0x88140503,  //  0003  GETMBR	R5	R2	K3
      0x541A0405,  //  0004  LDINT	R6	1030
      0x1C180806,  //  0005  EQ	R6	R4	R6
      0x781A0033,  //  0006  JMPF	R6	#003B
      0x1C180B04,  //  0007  EQ	R6	R5	K4
      0x781A000F,  //  0008  JMPF	R6	#0019
      0x88180105,  //  0009  GETMBR	R6	R0	K5
      0x4C1C0000,  //  000A  LDNIL	R7
      0x20180C07,  //  000B  NE	R6	R6	R7
      0x781A0005,  //  000C  JMPF	R6	#0013
      0x8C180706,  //  000D  GETMET	R6	R3	K6
      0x88200707,  //  000E  GETMBR	R8	R3	K7
      0x88240105,  //  000F  GETMBR	R9	R0	K5
      0x7C180600,  //  0010  CALL	R6	3
      0x80040C00,  //  0011  RET	1	R6
      0x70020004,  //  0012  JMP		#0018
      0x8C180706,  //  0013  GETMET	R6	R3	K6
      0x88200708,  //  0014  GETMBR	R8	R3	K8
      0x4C240000,  //  0015  LDNIL	R9
      0x7C180600,  //  0016  CALL	R6	3
      0x80040C00,  //  0017  RET	1	R6
      0x70020020,  //  0018  JMP		#003A
      0x1C180B09,  //  0019  EQ	R6	R5	K9
      0x781A0005,  //  001A  JMPF	R6	#0021
      0x8C180706,  //  001B  GETMET	R6	R3	K6
      0x88200707,  //  001C  GETMBR	R8	R3	K7
      0x5824000A,  //  001D  LDCONST	R9	K10
      0x7C180600,  //  001E  CALL	R6	3
      0x80040C00,  //  001F  RET	1	R6
      0x70020018,  //  0020  JMP		#003A
      0x1C180B0B,  //  0021  EQ	R6	R5	K11
      0x781A0005,  //  0022  JMPF	R6	#0029
      0x8C180706,  //  0023  GETMET	R6	R3	K6
      0x88200707,  //  0024  GETMBR	R8	R3	K7
      0x58240004,  //  0025  LDCONST	R9	K4
      0x7C180600,  //  0026  CALL	R6	3
      0x80040C00,  //  0027  RET	1	R6
      0x70020010,  //  0028  JMP		#003A
      0x541AFFFB,  //  0029  LDINT	R6	65532
      0x1C180A06,  //  002A  EQ	R6	R5	R6
      0x781A0005,  //  002B  JMPF	R6	#0032
      0x8C180706,  //  002C  GETMET	R6	R3	K6
      0x8820070C,  //  002D  GETMBR	R8	R3	K12
      0x58240004,  //  002E  LDCONST	R9	K4
      0x7C180600,  //  002F  CALL	R6	3
      0x80040C00,  //  0030  RET	1	R6
      0x70020007,  //  0031  JMP		#003A
      0x541AFFFC,  //  0032  LDINT	R6	65533
      0x1C180A06,  //  0033  EQ	R6	R5	R6
      0x781A0004,  //  0034  JMPF	R6	#003A
      0x8C180706,  //  0035  GETMET	R6	R3	K6
      0x8820070C,  //  0036  GETMBR	R8	R3	K12
      0x5824000A,  //  0037  LDCONST	R9	K10
      0x7C180600,  //  0038  CALL	R6	3
      0x80040C00,  //  0039  RET	1	R6
      0x70020007,  //  003A  JMP		#0043
      0x60180003,  //  003B  GETGBL	R6	G3
      0x5C1C0000,  //  003C  MOVE	R7	R0
      0x7C180200,  //  003D  CALL	R6	1
      0x8C180D0D,  //  003E  GETMET	R6	R6	K13
      0x5C200200,  //  003F  MOVE	R8	R1
      0x5C240400,  //  0040  MOVE	R9	R2
      0x7C180600,  //  0041  CALL	R6	3
      0x80040C00,  //  0042  RET	1	R6
      0x80000000,  //  0043  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified function: update_shadow
********************************************************************/
be_local_closure(Matter_Plugin_Sensor_Occupancy_update_shadow,   /* name */
  be_nested_proto(
    8,                          /* nstack */
    1,                          /* argc */
    2,                          /* varg */
    0,                          /* has upvals */
    NULL,                       /* no upvals */
    0,                          /* has sup protos */
    NULL,                       /* no sub protos */
    1,                          /* has constants */
    ( &(const bvalue[13]) {     /* constants */
    /* K0   */  be_nested_str_weak(update_shadow),
    /* K1   */  be_nested_str_weak(Switch),
    /* K2   */  be_nested_str_weak(tasmota_switch_index),
    /* K3   */  be_nested_str_weak(tasmota),
    /* K4   */  be_nested_str_weak(cmd),
    /* K5   */  be_nested_str_weak(Status_X208),
    /* K6   */  be_nested_str_weak(find),
    /* K7   */  be_nested_str_weak(StatusSNS),
    /* K8   */  be_nested_str_weak(contains),
    /* K9   */  be_nested_str_weak(ON),
    /* K10  */  be_nested_str_weak(shadow_occupancy),
    /* K11  */  be_nested_str_weak(attribute_updated),
    /* K12  */  be_const_int(0),
    }),
    be_str_weak(update_shadow),
    &be_const_str_solidified,
    ( &(const binstruction[41]) {  /* code */
      0x60040003,  //  0000  GETGBL	R1	G3
      0x5C080000,  //  0001  MOVE	R2	R0
      0x7C040200,  //  0002  CALL	R1	1
      0x8C040300,  //  0003  GETMET	R1	R1	K0
      0x7C040200,  //  0004  CALL	R1	1
      0x60040008,  //  0005  GETGBL	R1	G8
      0x88080102,  //  0006  GETMBR	R2	R0	K2
      0x7C040200,  //  0007  CALL	R1	1
      0x00060201,  //  0008  ADD	R1	K1	R1
      0xB80A0600,  //  0009  GETNGBL	R2	K3
      0x8C080504,  //  000A  GETMET	R2	R2	K4
      0x58100005,  //  000B  LDCONST	R4	K5
      0x50140200,  //  000C  LDBOOL	R5	1	0
      0x7C080600,  //  000D  CALL	R2	3
      0x4C0C0000,  //  000E  LDNIL	R3
      0x200C0403,  //  000F  NE	R3	R2	R3
      0x780E0003,  //  0010  JMPF	R3	#0015
      0x8C0C0506,  //  0011  GETMET	R3	R2	K6
      0x58140007,  //  0012  LDCONST	R5	K7
      0x7C0C0400,  //  0013  CALL	R3	2
      0x5C080600,  //  0014  MOVE	R2	R3
      0x4C0C0000,  //  0015  LDNIL	R3
      0x200C0403,  //  0016  NE	R3	R2	R3
      0x780E000F,  //  0017  JMPF	R3	#0028
      0x8C0C0508,  //  0018  GETMET	R3	R2	K8
      0x5C140200,  //  0019  MOVE	R5	R1
      0x7C0C0400,  //  001A  CALL	R3	2
      0x780E000B,  //  001B  JMPF	R3	#0028
      0x8C0C0506,  //  001C  GETMET	R3	R2	K6
      0x5C140200,  //  001D  MOVE	R5	R1
      0x7C0C0400,  //  001E  CALL	R3	2
      0x1C0C0709,  //  001F  EQ	R3	R3	K9
      0x8810010A,  //  0020  GETMBR	R4	R0	K10
      0x20100803,  //  0021  NE	R4	R4	R3
      0x78120003,  //  0022  JMPF	R4	#0027
      0x8C10010B,  //  0023  GETMET	R4	R0	K11
      0x541A0405,  //  0024  LDINT	R6	1030
      0x581C000C,  //  0025  LDCONST	R7	K12
      0x7C100600,  //  0026  CALL	R4	3
      0x90021403,  //  0027  SETMBR	R0	K10	R3
      0x80000000,  //  0028  RET	0
    })
  )
);
/*******************************************************************/


/********************************************************************
** Solidified class: Matter_Plugin_Sensor_Occupancy
********************************************************************/
extern const bclass be_class_Matter_Plugin_Device;
be_local_class(Matter_Plugin_Sensor_Occupancy,
    2,
    &be_class_Matter_Plugin_Device,
    be_nested_map(13,
    ( (struct bmapnode*) &(const bmapnode[]) {
        { be_const_key_weak(ARG, -1), be_nested_str_weak(switch) },
        { be_const_key_weak(ARG_TYPE, -1), be_const_static_closure(Matter_Plugin_Sensor_Occupancy__X3Clambda_X3E_closure) },
        { be_const_key_weak(TYPE, -1), be_nested_str_weak(occupancy) },
        { be_const_key_weak(ARG_HINT, 1), be_nested_str_weak(Switch_X3Cx_X3E_X20number) },
        { be_const_key_weak(UPDATE_TIME, -1), be_const_int(5000) },
        { be_const_key_weak(parse_configuration, -1), be_const_closure(Matter_Plugin_Sensor_Occupancy_parse_configuration_closure) },
        { be_const_key_weak(tasmota_switch_index, -1), be_const_var(0) },
        { be_const_key_weak(shadow_occupancy, 8), be_const_var(1) },
        { be_const_key_weak(update_shadow, 5), be_const_closure(Matter_Plugin_Sensor_Occupancy_update_shadow_closure) },
        { be_const_key_weak(NAME, 6), be_nested_str_weak(Occupancy) },
        { be_const_key_weak(CLUSTERS, -1), be_const_simple_instance(be_nested_simple_instance(&be_class_map, {
        be_const_map( *     be_nested_map(1,
    ( (struct bmapnode*) &(const bmapnode[]) {
        { be_const_key_int(1030, -1), be_const_simple_instance(be_nested_simple_instance(&be_class_list, {
        be_const_list( *     be_nested_list(5,
    ( (struct bvalue*) &(const bvalue[]) {
        be_const_int(0),
        be_const_int(1),
        be_const_int(2),
        be_const_int(65532),
        be_const_int(65533),
    }))    ) } )) },
    }))    ) } )) },
        { be_const_key_weak(read_attribute, 4), be_const_closure(Matter_Plugin_Sensor_Occupancy_read_attribute_closure) },
        { be_const_key_weak(TYPES, -1), be_const_simple_instance(be_nested_simple_instance(&be_class_map, {
        be_const_map( *     be_nested_map(1,
    ( (struct bmapnode*) &(const bmapnode[]) {
        { be_const_key_int(263, -1), be_const_int(2) },
    }))    ) } )) },
    })),
    be_str_weak(Matter_Plugin_Sensor_Occupancy)
);
/*******************************************************************/

void be_load_Matter_Plugin_Sensor_Occupancy_class(bvm *vm) {
    be_pushntvclass(vm, &be_class_Matter_Plugin_Sensor_Occupancy);
    be_setglobal(vm, "Matter_Plugin_Sensor_Occupancy");
    be_pop(vm, 1);
}
/********************************************************************/
/* End of solidification */
