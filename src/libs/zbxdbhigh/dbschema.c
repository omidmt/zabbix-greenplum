/*
** Zabbix
** Copyright (C) 2001-2015 Zabbix SIA
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**/

#include "common.h"
#include "dbschema.h"

const ZBX_TABLE	tables[] = {

#if defined(HAVE_IBM_DB2) || defined(HAVE_ORACLE)
#	define ZBX_TYPE_SHORTTEXT_LEN	2048
#else
#	define ZBX_TYPE_SHORTTEXT_LEN	65535
#endif

#if defined(HAVE_IBM_DB2)
#	define ZBX_TYPE_LONGTEXT_LEN	2048
#	define ZBX_TYPE_TEXT_LEN	2048
#else
#	define ZBX_TYPE_LONGTEXT_LEN	0
#	define ZBX_TYPE_TEXT_LEN	65535
#endif

	{"maintenances",	"maintenanceid",	0,
		{
		{"maintenanceid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"maintenance_type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"description",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"active_since",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"active_till",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"hosts",	"hostid",	0,
		{
		{"hostid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"proxy_hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	0,	0},
		{"host",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"disable_until",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"error",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"available",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"errors_from",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"lastaccess",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ipmi_authtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"ipmi_privilege",	"2",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"ipmi_username",	"",	NULL,	NULL,	16,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"ipmi_password",	"",	NULL,	NULL,	20,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"ipmi_disable_until",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ipmi_available",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"snmp_disable_until",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"snmp_available",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"maintenanceid",	NULL,	"maintenances",	"maintenanceid",	0,	ZBX_TYPE_ID,	0,	0},
		{"maintenance_status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"maintenance_type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"maintenance_from",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ipmi_errors_from",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"snmp_errors_from",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ipmi_error",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"snmp_error",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"jmx_disable_until",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"jmx_available",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"jmx_errors_from",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"jmx_error",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"flags",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"templateid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"description",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"groups",	"groupid",	0,
		{
		{"groupid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"internal",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"flags",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"group_prototype",	"group_prototypeid",	0,
		{
		{"group_prototypeid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"groupid",	NULL,	"groups",	"groupid",	0,	ZBX_TYPE_ID,	0,	0},
		{"templateid",	NULL,	"group_prototype",	"group_prototypeid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		NULL
	},
	{"group_discovery",	"groupid",	0,
		{
		{"groupid",	NULL,	"groups",	"groupid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"parent_group_prototypeid",	NULL,	"group_prototype",	"group_prototypeid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"lastcheck",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ts_delete",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"screens",	"screenid",	0,
		{
		{"screenid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	NULL,	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"hsize",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"vsize",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"templateid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		NULL
	},
	{"screens_items",	"screenitemid",	0,
		{
		{"screenitemid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"screenid",	NULL,	"screens",	"screenid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"resourcetype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"resourceid",	"0",	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"width",	"320",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"height",	"200",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"x",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"y",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"colspan",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"rowspan",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"elements",	"25",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"valign",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"halign",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"style",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"url",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"dynamic",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"sort_triggers",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"application",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"max_columns",	"3",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"slideshows",	"slideshowid",	0,
		{
		{"slideshowid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"delay",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"slides",	"slideid",	0,
		{
		{"slideid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"slideshowid",	NULL,	"slideshows",	"slideshowid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"screenid",	NULL,	"screens",	"screenid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"step",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"delay",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"drules",	"druleid",	0,
		{
		{"druleid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"proxy_hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	0,	0},
		{"name",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"iprange",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"delay",	"3600",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"nextcheck",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"dchecks",	"dcheckid",	0,
		{
		{"dcheckid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"druleid",	NULL,	"drules",	"druleid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"key_",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmp_community",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"ports",	"0",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_securityname",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_securitylevel",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_authpassphrase",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_privpassphrase",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"uniq",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_authprotocol",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_privprotocol",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_contextname",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{0}
		},
		NULL
	},
	{"applications",	"applicationid",	0,
		{
		{"applicationid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"name",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		"hostid,name"
	},
	{"httptest",	"httptestid",	0,
		{
		{"httptestid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"applicationid",	NULL,	"applications",	"applicationid",	0,	ZBX_TYPE_ID,	0,	0},
		{"nextcheck",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"delay",	"60",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"variables",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"agent",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"authentication",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"http_user",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"http_password",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"templateid",	NULL,	"httptest",	"httptestid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"http_proxy",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"retries",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"ssl_cert_file",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"ssl_key_file",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"ssl_key_password",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"verify_peer",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"verify_host",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"headers",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{0}
		},
		"hostid,name"
	},
	{"httpstep",	"httpstepid",	0,
		{
		{"httpstepid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"httptestid",	NULL,	"httptest",	"httptestid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"no",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"url",	"",	NULL,	NULL,	2048,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"timeout",	"15",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"posts",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"required",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"status_codes",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"variables",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"follow_redirects",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"retrieve_mode",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"headers",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{0}
		},
		NULL
	},
	{"interface",	"interfaceid",	0,
		{
		{"interfaceid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"main",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"useip",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"ip",	"127.0.0.1",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"dns",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"port",	"10050",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"bulk",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{0}
		},
		NULL
	},
	{"valuemaps",	"valuemapid",	0,
		{
		{"valuemapid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"items",	"itemid",	0,
		{
		{"itemid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmp_community",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmp_oid",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"name",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"key_",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"delay",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"history",	"90",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"trends",	"365",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"value_type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"trapper_hosts",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"units",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"multiplier",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"delta",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"snmpv3_securityname",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_securitylevel",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_authpassphrase",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_privpassphrase",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"formula",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"error",	"",	NULL,	NULL,	2048,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"lastlogsize",	"0",	NULL,	NULL,	0,	ZBX_TYPE_UINT,	ZBX_NOTNULL,	0},
		{"logtimefmt",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"templateid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"valuemapid",	NULL,	"valuemaps",	"valuemapid",	0,	ZBX_TYPE_ID,	0,	0},
		{"delay_flex",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"params",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"ipmi_sensor",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"data_type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"authtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"username",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"password",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"publickey",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"privatekey",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"mtime",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"flags",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"interfaceid",	NULL,	"interface",	"interfaceid",	0,	ZBX_TYPE_ID,	ZBX_PROXY,	0},
		{"port",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"description",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"inventory_link",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"lifetime",	"30",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"snmpv3_authprotocol",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"snmpv3_privprotocol",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"state",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"snmpv3_contextname",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"evaltype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"hostid,key_"
	},
	{"httpstepitem",	"httpstepitemid",	0,
		{
		{"httpstepitemid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"httpstepid",	NULL,	"httpstep",	"httpstepid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{0}
		},
		"httpstepid,itemid"
	},
	{"httptestitem",	"httptestitemid",	0,
		{
		{"httptestitemid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"httptestid",	NULL,	"httptest",	"httptestid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{0}
		},
		"httptestid,itemid"
	},
	{"media_type",	"mediatypeid",	0,
		{
		{"mediatypeid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"description",	"",	NULL,	NULL,	100,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"smtp_server",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"smtp_helo",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"smtp_email",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"exec_path",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"gsm_modem",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"username",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"passwd",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"description"
	},
	{"users",	"userid",	0,
		{
		{"userid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"alias",	"",	NULL,	NULL,	100,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	100,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"surname",	"",	NULL,	NULL,	100,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"passwd",	"",	NULL,	NULL,	32,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"autologin",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"autologout",	"900",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"lang",	"en_GB",	NULL,	NULL,	5,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"refresh",	"30",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"type",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"theme",	"default",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"attempt_failed",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"attempt_ip",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"attempt_clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"rows_per_page",	"50",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"alias"
	},
	{"usrgrp",	"usrgrpid",	0,
		{
		{"usrgrpid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"gui_access",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"users_status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"debug_mode",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"users_groups",	"id",	0,
		{
		{"id",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"usrgrpid",	NULL,	"usrgrp",	"usrgrpid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"userid",	NULL,	"users",	"userid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		"usrgrpid,userid"
	},
	{"scripts",	"scriptid",	0,
		{
		{"scriptid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"command",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"host_access",	"2",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"usrgrpid",	NULL,	"usrgrp",	"usrgrpid",	0,	ZBX_TYPE_ID,	0,	0},
		{"groupid",	NULL,	"groups",	"groupid",	0,	ZBX_TYPE_ID,	0,	0},
		{"description",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"confirmation",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"execute_on",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"actions",	"actionid",	0,
		{
		{"actionid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"eventsource",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"evaltype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"esc_period",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"def_shortdata",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"def_longdata",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"recovery_msg",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"r_shortdata",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"r_longdata",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"formula",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"operations",	"operationid",	0,
		{
		{"operationid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"actionid",	NULL,	"actions",	"actionid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"operationtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"esc_period",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"esc_step_from",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"esc_step_to",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"evaltype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"opmessage",	"operationid",	0,
		{
		{"operationid",	NULL,	"operations",	"operationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"default_msg",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"subject",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"message",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"mediatypeid",	NULL,	"media_type",	"mediatypeid",	0,	ZBX_TYPE_ID,	0,	0},
		{0}
		},
		NULL
	},
	{"opmessage_grp",	"opmessage_grpid",	0,
		{
		{"opmessage_grpid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"operationid",	NULL,	"operations",	"operationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"usrgrpid",	NULL,	"usrgrp",	"usrgrpid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{0}
		},
		"operationid,usrgrpid"
	},
	{"opmessage_usr",	"opmessage_usrid",	0,
		{
		{"opmessage_usrid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"operationid",	NULL,	"operations",	"operationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"userid",	NULL,	"users",	"userid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{0}
		},
		"operationid,userid"
	},
	{"opcommand",	"operationid",	0,
		{
		{"operationid",	NULL,	"operations",	"operationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"scriptid",	NULL,	"scripts",	"scriptid",	0,	ZBX_TYPE_ID,	0,	0},
		{"execute_on",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"port",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"authtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"username",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"password",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"publickey",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"privatekey",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"command",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"opcommand_hst",	"opcommand_hstid",	0,
		{
		{"opcommand_hstid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"operationid",	NULL,	"operations",	"operationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	0,	0},
		{0}
		},
		NULL
	},
	{"opcommand_grp",	"opcommand_grpid",	0,
		{
		{"opcommand_grpid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"operationid",	NULL,	"operations",	"operationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"groupid",	NULL,	"groups",	"groupid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"opgroup",	"opgroupid",	0,
		{
		{"opgroupid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"operationid",	NULL,	"operations",	"operationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"groupid",	NULL,	"groups",	"groupid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{0}
		},
		"operationid,groupid"
	},
	{"optemplate",	"optemplateid",	0,
		{
		{"optemplateid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"operationid",	NULL,	"operations",	"operationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"templateid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{0}
		},
		"operationid,templateid"
	},
	{"opconditions",	"opconditionid",	0,
		{
		{"opconditionid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"operationid",	NULL,	"operations",	"operationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"conditiontype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"operator",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"conditions",	"conditionid",	0,
		{
		{"conditionid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"actionid",	NULL,	"actions",	"actionid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"conditiontype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"operator",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"config",	"configid",	0,
		{
		{"configid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"refresh_unsupported",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"work_period",	"1-5,00:00-24:00",	NULL,	NULL,	100,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"alert_usrgrpid",	NULL,	"usrgrp",	"usrgrpid",	0,	ZBX_TYPE_ID,	0,	0},
		{"event_ack_enable",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"event_expire",	"7",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"event_show_max",	"100",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"default_theme",	"originalblue",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"authentication_type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ldap_host",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"ldap_port",	"389",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ldap_base_dn",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"ldap_bind_dn",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"ldap_bind_password",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"ldap_search_attribute",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"dropdown_first_entry",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"dropdown_first_remember",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"discovery_groupid",	NULL,	"groups",	"groupid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"max_in_table",	"50",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"search_limit",	"1000",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"severity_color_0",	"DBDBDB",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_color_1",	"D6F6FF",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_color_2",	"FFF6A5",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_color_3",	"FFB689",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_color_4",	"FF9999",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_color_5",	"FF3838",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_name_0",	"Not classified",	NULL,	NULL,	32,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_name_1",	"Information",	NULL,	NULL,	32,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_name_2",	"Warning",	NULL,	NULL,	32,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_name_3",	"Average",	NULL,	NULL,	32,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_name_4",	"High",	NULL,	NULL,	32,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity_name_5",	"Disaster",	NULL,	NULL,	32,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"ok_period",	"1800",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"blink_period",	"1800",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"problem_unack_color",	"DC0000",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"problem_ack_color",	"DC0000",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"ok_unack_color",	"00AA00",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"ok_ack_color",	"00AA00",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"problem_unack_style",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"problem_ack_style",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ok_unack_style",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ok_ack_style",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"snmptrap_logging",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"server_check_interval",	"10",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_events_mode",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_events_trigger",	"365",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_events_internal",	"365",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_events_discovery",	"365",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_events_autoreg",	"365",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_services_mode",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_services",	"365",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_audit_mode",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_audit",	"365",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_sessions_mode",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_sessions",	"365",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_history_mode",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_history_global",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_history",	"90",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_trends_mode",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_trends_global",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"hk_trends",	"365",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"triggers",	"triggerid",	0,
		{
		{"triggerid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"expression",	"",	NULL,	NULL,	2048,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"description",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"priority",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"lastchange",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"comments",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"error",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"templateid",	NULL,	"triggers",	"triggerid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"state",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"flags",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"trigger_depends",	"triggerdepid",	0,
		{
		{"triggerdepid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"triggerid_down",	NULL,	"triggers",	"triggerid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"triggerid_up",	NULL,	"triggers",	"triggerid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		"triggerid_down,triggerid_up"
	},
	{"functions",	"functionid",	0,
		{
		{"functionid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"triggerid",	NULL,	"triggers",	"triggerid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"function",	"",	NULL,	NULL,	12,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"parameter",	"0",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"graphs",	"graphid",	0,
		{
		{"graphid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"width",	"900",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"height",	"200",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"yaxismin",	"0",	NULL,	NULL,	0,	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	0},
		{"yaxismax",	"100",	NULL,	NULL,	0,	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	0},
		{"templateid",	NULL,	"graphs",	"graphid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"show_work_period",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"show_triggers",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"graphtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"show_legend",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"show_3d",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"percent_left",	"0",	NULL,	NULL,	0,	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	0},
		{"percent_right",	"0",	NULL,	NULL,	0,	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	0},
		{"ymin_type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ymax_type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ymin_itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	0,	0},
		{"ymax_itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	0,	0},
		{"flags",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"graphs_items",	"gitemid",	0,
		{
		{"gitemid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"graphid",	NULL,	"graphs",	"graphid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"drawtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"sortorder",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"color",	"009600",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"yaxisside",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"calc_fnc",	"2",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"graph_theme",	"graphthemeid",	0,
		{
		{"graphthemeid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"description",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"theme",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"backgroundcolor",	"F0F0F0",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"graphcolor",	"FFFFFF",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"graphbordercolor",	"222222",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"gridcolor",	"CCCCCC",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"maingridcolor",	"AAAAAA",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"gridbordercolor",	"000000",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"textcolor",	"202020",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"highlightcolor",	"AA4444",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"leftpercentilecolor",	"11CC11",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"rightpercentilecolor",	"CC1111",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"nonworktimecolor",	"CCCCCC",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"gridview",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"legendview",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"description"
	},
	{"globalmacro",	"globalmacroid",	0,
		{
		{"globalmacroid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"macro",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"value",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{0}
		},
		"macro"
	},
	{"hostmacro",	"hostmacroid",	0,
		{
		{"hostmacroid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"macro",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"value",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{0}
		},
		"hostid,macro"
	},
	{"hosts_groups",	"hostgroupid",	0,
		{
		{"hostgroupid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"groupid",	NULL,	"groups",	"groupid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		"hostid,groupid"
	},
	{"hosts_templates",	"hosttemplateid",	0,
		{
		{"hosttemplateid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"templateid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		"hostid,templateid"
	},
	{"items_applications",	"itemappid",	0,
		{
		{"itemappid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"applicationid",	NULL,	"applications",	"applicationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		"applicationid,itemid"
	},
	{"mappings",	"mappingid",	0,
		{
		{"mappingid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"valuemapid",	NULL,	"valuemaps",	"valuemapid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"value",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"newvalue",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"media",	"mediaid",	0,
		{
		{"mediaid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"userid",	NULL,	"users",	"userid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"mediatypeid",	NULL,	"media_type",	"mediatypeid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"sendto",	"",	NULL,	NULL,	100,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"active",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"severity",	"63",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"period",	"1-7,00:00-24:00",	NULL,	NULL,	100,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"rights",	"rightid",	0,
		{
		{"rightid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"groupid",	NULL,	"usrgrp",	"usrgrpid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"permission",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"id",	NULL,	"groups",	"groupid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		NULL
	},
	{"services",	"serviceid",	0,
		{
		{"serviceid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"algorithm",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"triggerid",	NULL,	"triggers",	"triggerid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"showsla",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"goodsla",	"99.9",	NULL,	NULL,	0,	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	0},
		{"sortorder",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"services_links",	"linkid",	0,
		{
		{"linkid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"serviceupid",	NULL,	"services",	"serviceid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"servicedownid",	NULL,	"services",	"serviceid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"soft",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"serviceupid,servicedownid"
	},
	{"services_times",	"timeid",	0,
		{
		{"timeid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"serviceid",	NULL,	"services",	"serviceid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ts_from",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ts_to",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"note",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"icon_map",	"iconmapid",	0,
		{
		{"iconmapid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"default_iconid",	NULL,	"images",	"imageid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"icon_mapping",	"iconmappingid",	0,
		{
		{"iconmappingid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"iconmapid",	NULL,	"icon_map",	"iconmapid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"iconid",	NULL,	"images",	"imageid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"inventory_link",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"expression",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"sortorder",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"sysmaps",	"sysmapid",	0,
		{
		{"sysmapid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"width",	"600",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"height",	"400",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"backgroundid",	NULL,	"images",	"imageid",	0,	ZBX_TYPE_ID,	0,	0},
		{"label_type",	"2",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"label_location",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"highlight",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"expandproblem",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"markelements",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"show_unack",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"grid_size",	"50",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"grid_show",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"grid_align",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"label_format",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"label_type_host",	"2",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"label_type_hostgroup",	"2",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"label_type_trigger",	"2",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"label_type_map",	"2",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"label_type_image",	"2",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"label_string_host",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"label_string_hostgroup",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"label_string_trigger",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"label_string_map",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"label_string_image",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"iconmapid",	NULL,	"icon_map",	"iconmapid",	0,	ZBX_TYPE_ID,	0,	0},
		{"expand_macros",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"severity_min",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"sysmaps_elements",	"selementid",	0,
		{
		{"selementid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"sysmapid",	NULL,	"sysmaps",	"sysmapid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"elementid",	"0",	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"elementtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"iconid_off",	NULL,	"images",	"imageid",	0,	ZBX_TYPE_ID,	0,	0},
		{"iconid_on",	NULL,	"images",	"imageid",	0,	ZBX_TYPE_ID,	0,	0},
		{"label",	"",	NULL,	NULL,	2048,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"label_location",	"-1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"x",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"y",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"iconid_disabled",	NULL,	"images",	"imageid",	0,	ZBX_TYPE_ID,	0,	0},
		{"iconid_maintenance",	NULL,	"images",	"imageid",	0,	ZBX_TYPE_ID,	0,	0},
		{"elementsubtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"areatype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"width",	"200",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"height",	"200",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"viewtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"use_iconmap",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"application",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"sysmaps_links",	"linkid",	0,
		{
		{"linkid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"sysmapid",	NULL,	"sysmaps",	"sysmapid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"selementid1",	NULL,	"sysmaps_elements",	"selementid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"selementid2",	NULL,	"sysmaps_elements",	"selementid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"drawtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"color",	"000000",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"label",	"",	NULL,	NULL,	2048,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"sysmaps_link_triggers",	"linktriggerid",	0,
		{
		{"linktriggerid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"linkid",	NULL,	"sysmaps_links",	"linkid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"triggerid",	NULL,	"triggers",	"triggerid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"drawtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"color",	"000000",	NULL,	NULL,	6,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		"linkid,triggerid"
	},
	{"sysmap_element_url",	"sysmapelementurlid",	0,
		{
		{"sysmapelementurlid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"selementid",	NULL,	"sysmaps_elements",	"selementid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"name",	NULL,	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		"selementid,name"
	},
	{"sysmap_url",	"sysmapurlid",	0,
		{
		{"sysmapurlid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"sysmapid",	NULL,	"sysmaps",	"sysmapid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"name",	NULL,	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"elementtype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"sysmapid,name"
	},
	{"maintenances_hosts",	"maintenance_hostid",	0,
		{
		{"maintenance_hostid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"maintenanceid",	NULL,	"maintenances",	"maintenanceid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		"maintenanceid,hostid"
	},
	{"maintenances_groups",	"maintenance_groupid",	0,
		{
		{"maintenance_groupid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"maintenanceid",	NULL,	"maintenances",	"maintenanceid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"groupid",	NULL,	"groups",	"groupid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		"maintenanceid,groupid"
	},
	{"timeperiods",	"timeperiodid",	0,
		{
		{"timeperiodid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"timeperiod_type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"every",	"1",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"month",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"dayofweek",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"day",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"start_time",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"period",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"start_date",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"maintenances_windows",	"maintenance_timeperiodid",	0,
		{
		{"maintenance_timeperiodid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"maintenanceid",	NULL,	"maintenances",	"maintenanceid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"timeperiodid",	NULL,	"timeperiods",	"timeperiodid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		"maintenanceid,timeperiodid"
	},
	{"regexps",	"regexpid",	0,
		{
		{"regexpid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"test_string",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"expressions",	"expressionid",	0,
		{
		{"expressionid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"regexpid",	NULL,	"regexps",	"regexpid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL | ZBX_PROXY,	ZBX_FK_CASCADE_DELETE},
		{"expression",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"expression_type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"exp_delimiter",	"",	NULL,	NULL,	1,	ZBX_TYPE_CHAR,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{"case_sensitive",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL | ZBX_PROXY,	0},
		{0}
		},
		NULL
	},
	{"ids",	"table_name,field_name",	0,
		{
		{"table_name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"field_name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"nextid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"alerts",	"alertid",	0,
		{
		{"alertid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"actionid",	NULL,	"actions",	"actionid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"eventid",	NULL,	"events",	"eventid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"userid",	NULL,	"users",	"userid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"mediatypeid",	NULL,	"media_type",	"mediatypeid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"sendto",	"",	NULL,	NULL,	100,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"subject",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"message",	"",	NULL,	NULL,	ZBX_TYPE_TEXT_LEN,	ZBX_TYPE_TEXT,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"retries",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"error",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"esc_step",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"alerttype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"history",	"",	0,
		{
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"0.0000",	NULL,	NULL,	0,	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	0},
		{"ns",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"history_uint",	"",	0,
		{
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"0",	NULL,	NULL,	0,	ZBX_TYPE_UINT,	ZBX_NOTNULL,	0},
		{"ns",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"history_str",	"",	0,
		{
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"ns",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"history_log",	"id",	0,
		{
		{"id",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"timestamp",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"source",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"",	NULL,	NULL,	ZBX_TYPE_TEXT_LEN,	ZBX_TYPE_TEXT,	ZBX_NOTNULL,	0},
		{"logeventid",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ns",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"itemid,id"
	},
	{"history_text",	"id",	0,
		{
		{"id",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"",	NULL,	NULL,	ZBX_TYPE_TEXT_LEN,	ZBX_TYPE_TEXT,	ZBX_NOTNULL,	0},
		{"ns",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"itemid,id"
	},
	{"proxy_history",	"id",	0,
		{
		{"id",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_UINT,	ZBX_NOTNULL,	0},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"timestamp",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"source",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"severity",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"",	NULL,	NULL,	ZBX_TYPE_LONGTEXT_LEN,	ZBX_TYPE_LONGTEXT,	ZBX_NOTNULL,	0},
		{"logeventid",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ns",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"state",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"proxy_dhistory",	"id",	0,
		{
		{"id",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_UINT,	ZBX_NOTNULL,	0},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"druleid",	NULL,	"drules",	"druleid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ip",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"port",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"key_",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"value",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"dcheckid",	NULL,	"dchecks",	"dcheckid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"dns",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"events",	"eventid",	0,
		{
		{"eventid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"source",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"object",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"objectid",	"0",	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"acknowledged",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ns",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"trends",	"itemid,clock",	0,
		{
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"num",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value_min",	"0.0000",	NULL,	NULL,	0,	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	0},
		{"value_avg",	"0.0000",	NULL,	NULL,	0,	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	0},
		{"value_max",	"0.0000",	NULL,	NULL,	0,	ZBX_TYPE_FLOAT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"trends_uint",	"itemid,clock",	0,
		{
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"num",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value_min",	"0",	NULL,	NULL,	0,	ZBX_TYPE_UINT,	ZBX_NOTNULL,	0},
		{"value_avg",	"0",	NULL,	NULL,	0,	ZBX_TYPE_UINT,	ZBX_NOTNULL,	0},
		{"value_max",	"0",	NULL,	NULL,	0,	ZBX_TYPE_UINT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"acknowledges",	"acknowledgeid",	0,
		{
		{"acknowledgeid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"userid",	NULL,	"users",	"userid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"eventid",	NULL,	"events",	"eventid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"message",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"auditlog",	"auditid",	0,
		{
		{"auditid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"userid",	NULL,	"users",	"userid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"action",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"resourcetype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"details",	"0",	NULL,	NULL,	128 ,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"ip",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"resourceid",	"0",	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"resourcename",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"auditlog_details",	"auditdetailid",	0,
		{
		{"auditdetailid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"auditid",	NULL,	"auditlog",	"auditid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"table_name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"field_name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"oldvalue",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"newvalue",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"service_alarms",	"servicealarmid",	0,
		{
		{"servicealarmid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"serviceid",	NULL,	"services",	"serviceid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"autoreg_host",	"autoreg_hostid",	0,
		{
		{"autoreg_hostid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"proxy_hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"host",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"listen_ip",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"listen_port",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"listen_dns",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"host_metadata",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"proxy_autoreg_host",	"id",	0,
		{
		{"id",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_UINT,	ZBX_NOTNULL,	0},
		{"clock",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"host",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"listen_ip",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"listen_port",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"listen_dns",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"host_metadata",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"dhosts",	"dhostid",	0,
		{
		{"dhostid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"druleid",	NULL,	"drules",	"druleid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"lastup",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"lastdown",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"dservices",	"dserviceid",	0,
		{
		{"dserviceid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"dhostid",	NULL,	"dhosts",	"dhostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"key_",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"value",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"port",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"lastup",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"lastdown",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"dcheckid",	NULL,	"dchecks",	"dcheckid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"ip",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"dns",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		"dcheckid,type,key_,ip,port"
	},
	{"escalations",	"escalationid",	0,
		{
		{"escalationid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"actionid",	NULL,	"actions",	"actionid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"triggerid",	NULL,	"triggers",	"triggerid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"eventid",	NULL,	"events",	"eventid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"r_eventid",	NULL,	"events",	"eventid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{"nextcheck",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"esc_step",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	0,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		"actionid,triggerid,itemid,escalationid"
	},
	{"globalvars",	"globalvarid",	0,
		{
		{"globalvarid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"snmp_lastsize",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"graph_discovery",	"graphid",	0,
		{
		{"graphid",	NULL,	"graphs",	"graphid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"parent_graphid",	NULL,	"graphs",	"graphid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"host_inventory",	"hostid",	0,
		{
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"inventory_mode",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"type",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"type_full",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"alias",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"os",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"os_full",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"os_short",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"serialno_a",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"serialno_b",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"tag",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"asset_tag",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"macaddress_a",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"macaddress_b",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"hardware",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"hardware_full",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"software",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"software_full",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"software_app_a",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"software_app_b",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"software_app_c",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"software_app_d",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"software_app_e",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"contact",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"location",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"location_lat",	"",	NULL,	NULL,	16,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"location_lon",	"",	NULL,	NULL,	16,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"notes",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"chassis",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"model",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"hw_arch",	"",	NULL,	NULL,	32,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"vendor",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"contract_number",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"installer_name",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"deployment_status",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url_a",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url_b",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url_c",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"host_networks",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"host_netmask",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"host_router",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"oob_ip",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"oob_netmask",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"oob_router",	"",	NULL,	NULL,	39,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"date_hw_purchase",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"date_hw_install",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"date_hw_expiry",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"date_hw_decomm",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"site_address_a",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"site_address_b",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"site_address_c",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"site_city",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"site_state",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"site_country",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"site_zip",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"site_rack",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"site_notes",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"poc_1_name",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_1_email",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_1_phone_a",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_1_phone_b",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_1_cell",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_1_screen",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_1_notes",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{"poc_2_name",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_2_email",	"",	NULL,	NULL,	128,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_2_phone_a",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_2_phone_b",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_2_cell",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_2_screen",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"poc_2_notes",	"",	NULL,	NULL,	ZBX_TYPE_SHORTTEXT_LEN,	ZBX_TYPE_SHORTTEXT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"housekeeper",	"housekeeperid",	0,
		{
		{"housekeeperid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"tablename",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"field",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"value",	NULL,	"items",	"value",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		NULL
	},
	{"images",	"imageid",	0,
		{
		{"imageid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"imagetype",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"name",	"0",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"image",	"",	NULL,	NULL,	0,	ZBX_TYPE_BLOB,	ZBX_NOTNULL,	0},
		{0}
		},
		"name"
	},
	{"item_discovery",	"itemdiscoveryid",	0,
		{
		{"itemdiscoveryid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"parent_itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"key_",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"lastcheck",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ts_delete",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		"itemid,parent_itemid"
	},
	{"host_discovery",	"hostid",	0,
		{
		{"hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"parent_hostid",	NULL,	"hosts",	"hostid",	0,	ZBX_TYPE_ID,	0,	0},
		{"parent_itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	0,	0},
		{"host",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"lastcheck",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"ts_delete",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"interface_discovery",	"interfaceid",	0,
		{
		{"interfaceid",	NULL,	"interface",	"interfaceid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"parent_interfaceid",	NULL,	"interface",	"interfaceid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		NULL
	},
	{"profiles",	"profileid",	0,
		{
		{"profileid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"userid",	NULL,	"users",	"userid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"idx",	"",	NULL,	NULL,	96,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"idx2",	"0",	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"value_id",	"0",	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"value_int",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"value_str",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"source",	"",	NULL,	NULL,	96,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"type",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"sessions",	"sessionid",	0,
		{
		{"sessionid",	"",	NULL,	NULL,	32,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"userid",	NULL,	"users",	"userid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"lastaccess",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"status",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"trigger_discovery",	"triggerid",	0,
		{
		{"triggerid",	NULL,	"triggers",	"triggerid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"parent_triggerid",	NULL,	"triggers",	"triggerid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"user_history",	"userhistoryid",	0,
		{
		{"userhistoryid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"userid",	NULL,	"users",	"userid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"title1",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url1",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"title2",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url2",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"title3",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url3",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"title4",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url4",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"title5",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"url5",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		"userid"
	},
	{"application_template",	"application_templateid",	0,
		{
		{"application_templateid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"applicationid",	NULL,	"applications",	"applicationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"templateid",	NULL,	"applications",	"applicationid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{0}
		},
		"applicationid,templateid"
	},
	{"item_condition",	"item_conditionid",	0,
		{
		{"item_conditionid",	NULL,	NULL,	NULL,	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	0},
		{"itemid",	NULL,	"items",	"itemid",	0,	ZBX_TYPE_ID,	ZBX_NOTNULL,	ZBX_FK_CASCADE_DELETE},
		{"operator",	"8",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"macro",	"",	NULL,	NULL,	64,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{"value",	"",	NULL,	NULL,	255,	ZBX_TYPE_CHAR,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{"dbversion",	"",	0,
		{
		{"mandatory",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{"optional",	"0",	NULL,	NULL,	0,	ZBX_TYPE_INT,	ZBX_NOTNULL,	0},
		{0}
		},
		NULL
	},
	{0}

#undef ZBX_TYPE_LONGTEXT_LEN
#undef ZBX_TYPE_SHORTTEXT_LEN

};
#if defined(HAVE_SQLITE3)
const char	*const db_schema = "\
CREATE TABLE maintenances (\n\
maintenanceid bigint  NOT NULL,\n\
name varchar(128) DEFAULT '' NOT NULL,\n\
maintenance_type integer DEFAULT '0' NOT NULL,\n\
description text DEFAULT '' NOT NULL,\n\
active_since integer DEFAULT '0' NOT NULL,\n\
active_till integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (maintenanceid)\n\
);\n\
CREATE INDEX maintenances_1 ON maintenances (active_since,active_till);\n\
CREATE UNIQUE INDEX maintenances_2 ON maintenances (name);\n\
CREATE TABLE hosts (\n\
hostid bigint  NOT NULL,\n\
proxy_hostid bigint  NULL REFERENCES hosts (hostid),\n\
host varchar(128) DEFAULT '' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
disable_until integer DEFAULT '0' NOT NULL,\n\
error varchar(128) DEFAULT '' NOT NULL,\n\
available integer DEFAULT '0' NOT NULL,\n\
errors_from integer DEFAULT '0' NOT NULL,\n\
lastaccess integer DEFAULT '0' NOT NULL,\n\
ipmi_authtype integer DEFAULT '0' NOT NULL,\n\
ipmi_privilege integer DEFAULT '2' NOT NULL,\n\
ipmi_username varchar(16) DEFAULT '' NOT NULL,\n\
ipmi_password varchar(20) DEFAULT '' NOT NULL,\n\
ipmi_disable_until integer DEFAULT '0' NOT NULL,\n\
ipmi_available integer DEFAULT '0' NOT NULL,\n\
snmp_disable_until integer DEFAULT '0' NOT NULL,\n\
snmp_available integer DEFAULT '0' NOT NULL,\n\
maintenanceid bigint  NULL REFERENCES maintenances (maintenanceid),\n\
maintenance_status integer DEFAULT '0' NOT NULL,\n\
maintenance_type integer DEFAULT '0' NOT NULL,\n\
maintenance_from integer DEFAULT '0' NOT NULL,\n\
ipmi_errors_from integer DEFAULT '0' NOT NULL,\n\
snmp_errors_from integer DEFAULT '0' NOT NULL,\n\
ipmi_error varchar(128) DEFAULT '' NOT NULL,\n\
snmp_error varchar(128) DEFAULT '' NOT NULL,\n\
jmx_disable_until integer DEFAULT '0' NOT NULL,\n\
jmx_available integer DEFAULT '0' NOT NULL,\n\
jmx_errors_from integer DEFAULT '0' NOT NULL,\n\
jmx_error varchar(128) DEFAULT '' NOT NULL,\n\
name varchar(128) DEFAULT '' NOT NULL,\n\
flags integer DEFAULT '0' NOT NULL,\n\
templateid bigint  NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
description text DEFAULT '' NOT NULL,\n\
PRIMARY KEY (hostid)\n\
);\n\
CREATE INDEX hosts_1 ON hosts (host);\n\
CREATE INDEX hosts_2 ON hosts (status);\n\
CREATE INDEX hosts_3 ON hosts (proxy_hostid);\n\
CREATE INDEX hosts_4 ON hosts (name);\n\
CREATE INDEX hosts_5 ON hosts (maintenanceid);\n\
CREATE TABLE groups (\n\
groupid bigint  NOT NULL,\n\
name varchar(64) DEFAULT '' NOT NULL,\n\
internal integer DEFAULT '0' NOT NULL,\n\
flags integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (groupid)\n\
);\n\
CREATE INDEX groups_1 ON groups (name);\n\
CREATE TABLE group_prototype (\n\
group_prototypeid bigint  NOT NULL,\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
name varchar(64) DEFAULT '' NOT NULL,\n\
groupid bigint  NULL REFERENCES groups (groupid),\n\
templateid bigint  NULL REFERENCES group_prototype (group_prototypeid) ON DELETE CASCADE,\n\
PRIMARY KEY (group_prototypeid)\n\
);\n\
CREATE INDEX group_prototype_1 ON group_prototype (hostid);\n\
CREATE TABLE group_discovery (\n\
groupid bigint  NOT NULL REFERENCES groups (groupid) ON DELETE CASCADE,\n\
parent_group_prototypeid bigint  NOT NULL REFERENCES group_prototype (group_prototypeid),\n\
name varchar(64) DEFAULT '' NOT NULL,\n\
lastcheck integer DEFAULT '0' NOT NULL,\n\
ts_delete integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (groupid)\n\
);\n\
CREATE TABLE screens (\n\
screenid bigint  NOT NULL,\n\
name varchar(255)  NOT NULL,\n\
hsize integer DEFAULT '1' NOT NULL,\n\
vsize integer DEFAULT '1' NOT NULL,\n\
templateid bigint  NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
PRIMARY KEY (screenid)\n\
);\n\
CREATE INDEX screens_1 ON screens (templateid);\n\
CREATE TABLE screens_items (\n\
screenitemid bigint  NOT NULL,\n\
screenid bigint  NOT NULL REFERENCES screens (screenid) ON DELETE CASCADE,\n\
resourcetype integer DEFAULT '0' NOT NULL,\n\
resourceid bigint DEFAULT '0' NOT NULL,\n\
width integer DEFAULT '320' NOT NULL,\n\
height integer DEFAULT '200' NOT NULL,\n\
x integer DEFAULT '0' NOT NULL,\n\
y integer DEFAULT '0' NOT NULL,\n\
colspan integer DEFAULT '1' NOT NULL,\n\
rowspan integer DEFAULT '1' NOT NULL,\n\
elements integer DEFAULT '25' NOT NULL,\n\
valign integer DEFAULT '0' NOT NULL,\n\
halign integer DEFAULT '0' NOT NULL,\n\
style integer DEFAULT '0' NOT NULL,\n\
url varchar(255) DEFAULT '' NOT NULL,\n\
dynamic integer DEFAULT '0' NOT NULL,\n\
sort_triggers integer DEFAULT '0' NOT NULL,\n\
application varchar(255) DEFAULT '' NOT NULL,\n\
max_columns integer DEFAULT '3' NOT NULL,\n\
PRIMARY KEY (screenitemid)\n\
);\n\
CREATE INDEX screens_items_1 ON screens_items (screenid);\n\
CREATE TABLE slideshows (\n\
slideshowid bigint  NOT NULL,\n\
name varchar(255) DEFAULT '' NOT NULL,\n\
delay integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (slideshowid)\n\
);\n\
CREATE UNIQUE INDEX slideshows_1 ON slideshows (name);\n\
CREATE TABLE slides (\n\
slideid bigint  NOT NULL,\n\
slideshowid bigint  NOT NULL REFERENCES slideshows (slideshowid) ON DELETE CASCADE,\n\
screenid bigint  NOT NULL REFERENCES screens (screenid) ON DELETE CASCADE,\n\
step integer DEFAULT '0' NOT NULL,\n\
delay integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (slideid)\n\
);\n\
CREATE INDEX slides_1 ON slides (slideshowid);\n\
CREATE INDEX slides_2 ON slides (screenid);\n\
CREATE TABLE drules (\n\
druleid bigint  NOT NULL,\n\
proxy_hostid bigint  NULL REFERENCES hosts (hostid),\n\
name varchar(255) DEFAULT '' NOT NULL,\n\
iprange varchar(255) DEFAULT '' NOT NULL,\n\
delay integer DEFAULT '3600' NOT NULL,\n\
nextcheck integer DEFAULT '0' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (druleid)\n\
);\n\
CREATE INDEX drules_1 ON drules (proxy_hostid);\n\
CREATE UNIQUE INDEX drules_2 ON drules (name);\n\
CREATE TABLE dchecks (\n\
dcheckid bigint  NOT NULL,\n\
druleid bigint  NOT NULL REFERENCES drules (druleid) ON DELETE CASCADE,\n\
type integer DEFAULT '0' NOT NULL,\n\
key_ varchar(255) DEFAULT '' NOT NULL,\n\
snmp_community varchar(255) DEFAULT '' NOT NULL,\n\
ports varchar(255) DEFAULT '0' NOT NULL,\n\
snmpv3_securityname varchar(64) DEFAULT '' NOT NULL,\n\
snmpv3_securitylevel integer DEFAULT '0' NOT NULL,\n\
snmpv3_authpassphrase varchar(64) DEFAULT '' NOT NULL,\n\
snmpv3_privpassphrase varchar(64) DEFAULT '' NOT NULL,\n\
uniq integer DEFAULT '0' NOT NULL,\n\
snmpv3_authprotocol integer DEFAULT '0' NOT NULL,\n\
snmpv3_privprotocol integer DEFAULT '0' NOT NULL,\n\
snmpv3_contextname varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (dcheckid)\n\
);\n\
CREATE INDEX dchecks_1 ON dchecks (druleid);\n\
CREATE TABLE applications (\n\
applicationid bigint  NOT NULL,\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
name varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (applicationid)\n\
);\n\
CREATE UNIQUE INDEX applications_2 ON applications (hostid,name);\n\
CREATE TABLE httptest (\n\
httptestid bigint  NOT NULL,\n\
name varchar(64) DEFAULT '' NOT NULL,\n\
applicationid bigint  NULL REFERENCES applications (applicationid),\n\
nextcheck integer DEFAULT '0' NOT NULL,\n\
delay integer DEFAULT '60' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
variables text DEFAULT '' NOT NULL,\n\
agent varchar(255) DEFAULT '' NOT NULL,\n\
authentication integer DEFAULT '0' NOT NULL,\n\
http_user varchar(64) DEFAULT '' NOT NULL,\n\
http_password varchar(64) DEFAULT '' NOT NULL,\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
templateid bigint  NULL REFERENCES httptest (httptestid) ON DELETE CASCADE,\n\
http_proxy varchar(255) DEFAULT '' NOT NULL,\n\
retries integer DEFAULT '1' NOT NULL,\n\
ssl_cert_file varchar(255) DEFAULT '' NOT NULL,\n\
ssl_key_file varchar(255) DEFAULT '' NOT NULL,\n\
ssl_key_password varchar(64) DEFAULT '' NOT NULL,\n\
verify_peer integer DEFAULT '0' NOT NULL,\n\
verify_host integer DEFAULT '0' NOT NULL,\n\
headers text DEFAULT '' NOT NULL,\n\
PRIMARY KEY (httptestid)\n\
);\n\
CREATE INDEX httptest_1 ON httptest (applicationid);\n\
CREATE UNIQUE INDEX httptest_2 ON httptest (hostid,name);\n\
CREATE INDEX httptest_3 ON httptest (status);\n\
CREATE INDEX httptest_4 ON httptest (templateid);\n\
CREATE TABLE httpstep (\n\
httpstepid bigint  NOT NULL,\n\
httptestid bigint  NOT NULL REFERENCES httptest (httptestid) ON DELETE CASCADE,\n\
name varchar(64) DEFAULT '' NOT NULL,\n\
no integer DEFAULT '0' NOT NULL,\n\
url varchar(2048) DEFAULT '' NOT NULL,\n\
timeout integer DEFAULT '15' NOT NULL,\n\
posts text DEFAULT '' NOT NULL,\n\
required varchar(255) DEFAULT '' NOT NULL,\n\
status_codes varchar(255) DEFAULT '' NOT NULL,\n\
variables text DEFAULT '' NOT NULL,\n\
follow_redirects integer DEFAULT '1' NOT NULL,\n\
retrieve_mode integer DEFAULT '0' NOT NULL,\n\
headers text DEFAULT '' NOT NULL,\n\
PRIMARY KEY (httpstepid)\n\
);\n\
CREATE INDEX httpstep_1 ON httpstep (httptestid);\n\
CREATE TABLE interface (\n\
interfaceid bigint  NOT NULL,\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
main integer DEFAULT '0' NOT NULL,\n\
type integer DEFAULT '0' NOT NULL,\n\
useip integer DEFAULT '1' NOT NULL,\n\
ip varchar(64) DEFAULT '127.0.0.1' NOT NULL,\n\
dns varchar(64) DEFAULT '' NOT NULL,\n\
port varchar(64) DEFAULT '10050' NOT NULL,\n\
bulk integer DEFAULT '1' NOT NULL,\n\
PRIMARY KEY (interfaceid)\n\
);\n\
CREATE INDEX interface_1 ON interface (hostid,type);\n\
CREATE INDEX interface_2 ON interface (ip,dns);\n\
CREATE TABLE valuemaps (\n\
valuemapid bigint  NOT NULL,\n\
name varchar(64) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (valuemapid)\n\
);\n\
CREATE UNIQUE INDEX valuemaps_1 ON valuemaps (name);\n\
CREATE TABLE items (\n\
itemid bigint  NOT NULL,\n\
type integer DEFAULT '0' NOT NULL,\n\
snmp_community varchar(64) DEFAULT '' NOT NULL,\n\
snmp_oid varchar(255) DEFAULT '' NOT NULL,\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
name varchar(255) DEFAULT '' NOT NULL,\n\
key_ varchar(255) DEFAULT '' NOT NULL,\n\
delay integer DEFAULT '0' NOT NULL,\n\
history integer DEFAULT '90' NOT NULL,\n\
trends integer DEFAULT '365' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
value_type integer DEFAULT '0' NOT NULL,\n\
trapper_hosts varchar(255) DEFAULT '' NOT NULL,\n\
units varchar(255) DEFAULT '' NOT NULL,\n\
multiplier integer DEFAULT '0' NOT NULL,\n\
delta integer DEFAULT '0' NOT NULL,\n\
snmpv3_securityname varchar(64) DEFAULT '' NOT NULL,\n\
snmpv3_securitylevel integer DEFAULT '0' NOT NULL,\n\
snmpv3_authpassphrase varchar(64) DEFAULT '' NOT NULL,\n\
snmpv3_privpassphrase varchar(64) DEFAULT '' NOT NULL,\n\
formula varchar(255) DEFAULT '' NOT NULL,\n\
error varchar(2048) DEFAULT '' NOT NULL,\n\
lastlogsize bigint DEFAULT '0' NOT NULL,\n\
logtimefmt varchar(64) DEFAULT '' NOT NULL,\n\
templateid bigint  NULL REFERENCES items (itemid) ON DELETE CASCADE,\n\
valuemapid bigint  NULL REFERENCES valuemaps (valuemapid),\n\
delay_flex varchar(255) DEFAULT '' NOT NULL,\n\
params text DEFAULT '' NOT NULL,\n\
ipmi_sensor varchar(128) DEFAULT '' NOT NULL,\n\
data_type integer DEFAULT '0' NOT NULL,\n\
authtype integer DEFAULT '0' NOT NULL,\n\
username varchar(64) DEFAULT '' NOT NULL,\n\
password varchar(64) DEFAULT '' NOT NULL,\n\
publickey varchar(64) DEFAULT '' NOT NULL,\n\
privatekey varchar(64) DEFAULT '' NOT NULL,\n\
mtime integer DEFAULT '0' NOT NULL,\n\
flags integer DEFAULT '0' NOT NULL,\n\
interfaceid bigint  NULL REFERENCES interface (interfaceid),\n\
port varchar(64) DEFAULT '' NOT NULL,\n\
description text DEFAULT '' NOT NULL,\n\
inventory_link integer DEFAULT '0' NOT NULL,\n\
lifetime varchar(64) DEFAULT '30' NOT NULL,\n\
snmpv3_authprotocol integer DEFAULT '0' NOT NULL,\n\
snmpv3_privprotocol integer DEFAULT '0' NOT NULL,\n\
state integer DEFAULT '0' NOT NULL,\n\
snmpv3_contextname varchar(255) DEFAULT '' NOT NULL,\n\
evaltype integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (itemid)\n\
);\n\
CREATE UNIQUE INDEX items_1 ON items (hostid,key_);\n\
CREATE INDEX items_3 ON items (status);\n\
CREATE INDEX items_4 ON items (templateid);\n\
CREATE INDEX items_5 ON items (valuemapid);\n\
CREATE INDEX items_6 ON items (interfaceid);\n\
CREATE TABLE httpstepitem (\n\
httpstepitemid bigint  NOT NULL,\n\
httpstepid bigint  NOT NULL REFERENCES httpstep (httpstepid) ON DELETE CASCADE,\n\
itemid bigint  NOT NULL REFERENCES items (itemid) ON DELETE CASCADE,\n\
type integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (httpstepitemid)\n\
);\n\
CREATE UNIQUE INDEX httpstepitem_1 ON httpstepitem (httpstepid,itemid);\n\
CREATE INDEX httpstepitem_2 ON httpstepitem (itemid);\n\
CREATE TABLE httptestitem (\n\
httptestitemid bigint  NOT NULL,\n\
httptestid bigint  NOT NULL REFERENCES httptest (httptestid) ON DELETE CASCADE,\n\
itemid bigint  NOT NULL REFERENCES items (itemid) ON DELETE CASCADE,\n\
type integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (httptestitemid)\n\
);\n\
CREATE UNIQUE INDEX httptestitem_1 ON httptestitem (httptestid,itemid);\n\
CREATE INDEX httptestitem_2 ON httptestitem (itemid);\n\
CREATE TABLE media_type (\n\
mediatypeid bigint  NOT NULL,\n\
type integer DEFAULT '0' NOT NULL,\n\
description varchar(100) DEFAULT '' NOT NULL,\n\
smtp_server varchar(255) DEFAULT '' NOT NULL,\n\
smtp_helo varchar(255) DEFAULT '' NOT NULL,\n\
smtp_email varchar(255) DEFAULT '' NOT NULL,\n\
exec_path varchar(255) DEFAULT '' NOT NULL,\n\
gsm_modem varchar(255) DEFAULT '' NOT NULL,\n\
username varchar(255) DEFAULT '' NOT NULL,\n\
passwd varchar(255) DEFAULT '' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (mediatypeid)\n\
);\n\
CREATE UNIQUE INDEX media_type_1 ON media_type (description);\n\
CREATE TABLE users (\n\
userid bigint  NOT NULL,\n\
alias varchar(100) DEFAULT '' NOT NULL,\n\
name varchar(100) DEFAULT '' NOT NULL,\n\
surname varchar(100) DEFAULT '' NOT NULL,\n\
passwd char(32) DEFAULT '' NOT NULL,\n\
url varchar(255) DEFAULT '' NOT NULL,\n\
autologin integer DEFAULT '0' NOT NULL,\n\
autologout integer DEFAULT '900' NOT NULL,\n\
lang varchar(5) DEFAULT 'en_GB' NOT NULL,\n\
refresh integer DEFAULT '30' NOT NULL,\n\
type integer DEFAULT '1' NOT NULL,\n\
theme varchar(128) DEFAULT 'default' NOT NULL,\n\
attempt_failed integer DEFAULT 0 NOT NULL,\n\
attempt_ip varchar(39) DEFAULT '' NOT NULL,\n\
attempt_clock integer DEFAULT 0 NOT NULL,\n\
rows_per_page integer DEFAULT 50 NOT NULL,\n\
PRIMARY KEY (userid)\n\
);\n\
CREATE UNIQUE INDEX users_1 ON users (alias);\n\
CREATE TABLE usrgrp (\n\
usrgrpid bigint  NOT NULL,\n\
name varchar(64) DEFAULT '' NOT NULL,\n\
gui_access integer DEFAULT '0' NOT NULL,\n\
users_status integer DEFAULT '0' NOT NULL,\n\
debug_mode integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (usrgrpid)\n\
);\n\
CREATE UNIQUE INDEX usrgrp_1 ON usrgrp (name);\n\
CREATE TABLE users_groups (\n\
id bigint  NOT NULL,\n\
usrgrpid bigint  NOT NULL REFERENCES usrgrp (usrgrpid) ON DELETE CASCADE,\n\
userid bigint  NOT NULL REFERENCES users (userid) ON DELETE CASCADE,\n\
PRIMARY KEY (id)\n\
);\n\
CREATE UNIQUE INDEX users_groups_1 ON users_groups (usrgrpid,userid);\n\
CREATE INDEX users_groups_2 ON users_groups (userid);\n\
CREATE TABLE scripts (\n\
scriptid bigint  NOT NULL,\n\
name varchar(255) DEFAULT '' NOT NULL,\n\
command varchar(255) DEFAULT '' NOT NULL,\n\
host_access integer DEFAULT '2' NOT NULL,\n\
usrgrpid bigint  NULL REFERENCES usrgrp (usrgrpid),\n\
groupid bigint  NULL REFERENCES groups (groupid),\n\
description text DEFAULT '' NOT NULL,\n\
confirmation varchar(255) DEFAULT '' NOT NULL,\n\
type integer DEFAULT '0' NOT NULL,\n\
execute_on integer DEFAULT '1' NOT NULL,\n\
PRIMARY KEY (scriptid)\n\
);\n\
CREATE INDEX scripts_1 ON scripts (usrgrpid);\n\
CREATE INDEX scripts_2 ON scripts (groupid);\n\
CREATE UNIQUE INDEX scripts_3 ON scripts (name);\n\
CREATE TABLE actions (\n\
actionid bigint  NOT NULL,\n\
name varchar(255) DEFAULT '' NOT NULL,\n\
eventsource integer DEFAULT '0' NOT NULL,\n\
evaltype integer DEFAULT '0' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
esc_period integer DEFAULT '0' NOT NULL,\n\
def_shortdata varchar(255) DEFAULT '' NOT NULL,\n\
def_longdata text DEFAULT '' NOT NULL,\n\
recovery_msg integer DEFAULT '0' NOT NULL,\n\
r_shortdata varchar(255) DEFAULT '' NOT NULL,\n\
r_longdata text DEFAULT '' NOT NULL,\n\
formula varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (actionid)\n\
);\n\
CREATE INDEX actions_1 ON actions (eventsource,status);\n\
CREATE UNIQUE INDEX actions_2 ON actions (name);\n\
CREATE TABLE operations (\n\
operationid bigint  NOT NULL,\n\
actionid bigint  NOT NULL REFERENCES actions (actionid) ON DELETE CASCADE,\n\
operationtype integer DEFAULT '0' NOT NULL,\n\
esc_period integer DEFAULT '0' NOT NULL,\n\
esc_step_from integer DEFAULT '1' NOT NULL,\n\
esc_step_to integer DEFAULT '1' NOT NULL,\n\
evaltype integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (operationid)\n\
);\n\
CREATE INDEX operations_1 ON operations (actionid);\n\
CREATE TABLE opmessage (\n\
operationid bigint  NOT NULL REFERENCES operations (operationid) ON DELETE CASCADE,\n\
default_msg integer DEFAULT '0' NOT NULL,\n\
subject varchar(255) DEFAULT '' NOT NULL,\n\
message text DEFAULT '' NOT NULL,\n\
mediatypeid bigint  NULL REFERENCES media_type (mediatypeid),\n\
PRIMARY KEY (operationid)\n\
);\n\
CREATE INDEX opmessage_1 ON opmessage (mediatypeid);\n\
CREATE TABLE opmessage_grp (\n\
opmessage_grpid bigint  NOT NULL,\n\
operationid bigint  NOT NULL REFERENCES operations (operationid) ON DELETE CASCADE,\n\
usrgrpid bigint  NOT NULL REFERENCES usrgrp (usrgrpid),\n\
PRIMARY KEY (opmessage_grpid)\n\
);\n\
CREATE UNIQUE INDEX opmessage_grp_1 ON opmessage_grp (operationid,usrgrpid);\n\
CREATE INDEX opmessage_grp_2 ON opmessage_grp (usrgrpid);\n\
CREATE TABLE opmessage_usr (\n\
opmessage_usrid bigint  NOT NULL,\n\
operationid bigint  NOT NULL REFERENCES operations (operationid) ON DELETE CASCADE,\n\
userid bigint  NOT NULL REFERENCES users (userid),\n\
PRIMARY KEY (opmessage_usrid)\n\
);\n\
CREATE UNIQUE INDEX opmessage_usr_1 ON opmessage_usr (operationid,userid);\n\
CREATE INDEX opmessage_usr_2 ON opmessage_usr (userid);\n\
CREATE TABLE opcommand (\n\
operationid bigint  NOT NULL REFERENCES operations (operationid) ON DELETE CASCADE,\n\
type integer DEFAULT '0' NOT NULL,\n\
scriptid bigint  NULL REFERENCES scripts (scriptid),\n\
execute_on integer DEFAULT '0' NOT NULL,\n\
port varchar(64) DEFAULT '' NOT NULL,\n\
authtype integer DEFAULT '0' NOT NULL,\n\
username varchar(64) DEFAULT '' NOT NULL,\n\
password varchar(64) DEFAULT '' NOT NULL,\n\
publickey varchar(64) DEFAULT '' NOT NULL,\n\
privatekey varchar(64) DEFAULT '' NOT NULL,\n\
command text DEFAULT '' NOT NULL,\n\
PRIMARY KEY (operationid)\n\
);\n\
CREATE INDEX opcommand_1 ON opcommand (scriptid);\n\
CREATE TABLE opcommand_hst (\n\
opcommand_hstid bigint  NOT NULL,\n\
operationid bigint  NOT NULL REFERENCES operations (operationid) ON DELETE CASCADE,\n\
hostid bigint  NULL REFERENCES hosts (hostid),\n\
PRIMARY KEY (opcommand_hstid)\n\
);\n\
CREATE INDEX opcommand_hst_1 ON opcommand_hst (operationid);\n\
CREATE INDEX opcommand_hst_2 ON opcommand_hst (hostid);\n\
CREATE TABLE opcommand_grp (\n\
opcommand_grpid bigint  NOT NULL,\n\
operationid bigint  NOT NULL REFERENCES operations (operationid) ON DELETE CASCADE,\n\
groupid bigint  NOT NULL REFERENCES groups (groupid),\n\
PRIMARY KEY (opcommand_grpid)\n\
);\n\
CREATE INDEX opcommand_grp_1 ON opcommand_grp (operationid);\n\
CREATE INDEX opcommand_grp_2 ON opcommand_grp (groupid);\n\
CREATE TABLE opgroup (\n\
opgroupid bigint  NOT NULL,\n\
operationid bigint  NOT NULL REFERENCES operations (operationid) ON DELETE CASCADE,\n\
groupid bigint  NOT NULL REFERENCES groups (groupid),\n\
PRIMARY KEY (opgroupid)\n\
);\n\
CREATE UNIQUE INDEX opgroup_1 ON opgroup (operationid,groupid);\n\
CREATE INDEX opgroup_2 ON opgroup (groupid);\n\
CREATE TABLE optemplate (\n\
optemplateid bigint  NOT NULL,\n\
operationid bigint  NOT NULL REFERENCES operations (operationid) ON DELETE CASCADE,\n\
templateid bigint  NOT NULL REFERENCES hosts (hostid),\n\
PRIMARY KEY (optemplateid)\n\
);\n\
CREATE UNIQUE INDEX optemplate_1 ON optemplate (operationid,templateid);\n\
CREATE INDEX optemplate_2 ON optemplate (templateid);\n\
CREATE TABLE opconditions (\n\
opconditionid bigint  NOT NULL,\n\
operationid bigint  NOT NULL REFERENCES operations (operationid) ON DELETE CASCADE,\n\
conditiontype integer DEFAULT '0' NOT NULL,\n\
operator integer DEFAULT '0' NOT NULL,\n\
value varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (opconditionid)\n\
);\n\
CREATE INDEX opconditions_1 ON opconditions (operationid);\n\
CREATE TABLE conditions (\n\
conditionid bigint  NOT NULL,\n\
actionid bigint  NOT NULL REFERENCES actions (actionid) ON DELETE CASCADE,\n\
conditiontype integer DEFAULT '0' NOT NULL,\n\
operator integer DEFAULT '0' NOT NULL,\n\
value varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (conditionid)\n\
);\n\
CREATE INDEX conditions_1 ON conditions (actionid);\n\
CREATE TABLE config (\n\
configid bigint  NOT NULL,\n\
refresh_unsupported integer DEFAULT '0' NOT NULL,\n\
work_period varchar(100) DEFAULT '1-5,00:00-24:00' NOT NULL,\n\
alert_usrgrpid bigint  NULL REFERENCES usrgrp (usrgrpid),\n\
event_ack_enable integer DEFAULT '1' NOT NULL,\n\
event_expire integer DEFAULT '7' NOT NULL,\n\
event_show_max integer DEFAULT '100' NOT NULL,\n\
default_theme varchar(128) DEFAULT 'originalblue' NOT NULL,\n\
authentication_type integer DEFAULT '0' NOT NULL,\n\
ldap_host varchar(255) DEFAULT '' NOT NULL,\n\
ldap_port integer DEFAULT 389 NOT NULL,\n\
ldap_base_dn varchar(255) DEFAULT '' NOT NULL,\n\
ldap_bind_dn varchar(255) DEFAULT '' NOT NULL,\n\
ldap_bind_password varchar(128) DEFAULT '' NOT NULL,\n\
ldap_search_attribute varchar(128) DEFAULT '' NOT NULL,\n\
dropdown_first_entry integer DEFAULT '1' NOT NULL,\n\
dropdown_first_remember integer DEFAULT '1' NOT NULL,\n\
discovery_groupid bigint  NOT NULL REFERENCES groups (groupid),\n\
max_in_table integer DEFAULT '50' NOT NULL,\n\
search_limit integer DEFAULT '1000' NOT NULL,\n\
severity_color_0 varchar(6) DEFAULT 'DBDBDB' NOT NULL,\n\
severity_color_1 varchar(6) DEFAULT 'D6F6FF' NOT NULL,\n\
severity_color_2 varchar(6) DEFAULT 'FFF6A5' NOT NULL,\n\
severity_color_3 varchar(6) DEFAULT 'FFB689' NOT NULL,\n\
severity_color_4 varchar(6) DEFAULT 'FF9999' NOT NULL,\n\
severity_color_5 varchar(6) DEFAULT 'FF3838' NOT NULL,\n\
severity_name_0 varchar(32) DEFAULT 'Not classified' NOT NULL,\n\
severity_name_1 varchar(32) DEFAULT 'Information' NOT NULL,\n\
severity_name_2 varchar(32) DEFAULT 'Warning' NOT NULL,\n\
severity_name_3 varchar(32) DEFAULT 'Average' NOT NULL,\n\
severity_name_4 varchar(32) DEFAULT 'High' NOT NULL,\n\
severity_name_5 varchar(32) DEFAULT 'Disaster' NOT NULL,\n\
ok_period integer DEFAULT '1800' NOT NULL,\n\
blink_period integer DEFAULT '1800' NOT NULL,\n\
problem_unack_color varchar(6) DEFAULT 'DC0000' NOT NULL,\n\
problem_ack_color varchar(6) DEFAULT 'DC0000' NOT NULL,\n\
ok_unack_color varchar(6) DEFAULT '00AA00' NOT NULL,\n\
ok_ack_color varchar(6) DEFAULT '00AA00' NOT NULL,\n\
problem_unack_style integer DEFAULT '1' NOT NULL,\n\
problem_ack_style integer DEFAULT '1' NOT NULL,\n\
ok_unack_style integer DEFAULT '1' NOT NULL,\n\
ok_ack_style integer DEFAULT '1' NOT NULL,\n\
snmptrap_logging integer DEFAULT '1' NOT NULL,\n\
server_check_interval integer DEFAULT '10' NOT NULL,\n\
hk_events_mode integer DEFAULT '1' NOT NULL,\n\
hk_events_trigger integer DEFAULT '365' NOT NULL,\n\
hk_events_internal integer DEFAULT '365' NOT NULL,\n\
hk_events_discovery integer DEFAULT '365' NOT NULL,\n\
hk_events_autoreg integer DEFAULT '365' NOT NULL,\n\
hk_services_mode integer DEFAULT '1' NOT NULL,\n\
hk_services integer DEFAULT '365' NOT NULL,\n\
hk_audit_mode integer DEFAULT '1' NOT NULL,\n\
hk_audit integer DEFAULT '365' NOT NULL,\n\
hk_sessions_mode integer DEFAULT '1' NOT NULL,\n\
hk_sessions integer DEFAULT '365' NOT NULL,\n\
hk_history_mode integer DEFAULT '1' NOT NULL,\n\
hk_history_global integer DEFAULT '0' NOT NULL,\n\
hk_history integer DEFAULT '90' NOT NULL,\n\
hk_trends_mode integer DEFAULT '1' NOT NULL,\n\
hk_trends_global integer DEFAULT '0' NOT NULL,\n\
hk_trends integer DEFAULT '365' NOT NULL,\n\
PRIMARY KEY (configid)\n\
);\n\
CREATE INDEX config_1 ON config (alert_usrgrpid);\n\
CREATE INDEX config_2 ON config (discovery_groupid);\n\
CREATE TABLE triggers (\n\
triggerid bigint  NOT NULL,\n\
expression varchar(2048) DEFAULT '' NOT NULL,\n\
description varchar(255) DEFAULT '' NOT NULL,\n\
url varchar(255) DEFAULT '' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
value integer DEFAULT '0' NOT NULL,\n\
priority integer DEFAULT '0' NOT NULL,\n\
lastchange integer DEFAULT '0' NOT NULL,\n\
comments text DEFAULT '' NOT NULL,\n\
error varchar(128) DEFAULT '' NOT NULL,\n\
templateid bigint  NULL REFERENCES triggers (triggerid) ON DELETE CASCADE,\n\
type integer DEFAULT '0' NOT NULL,\n\
state integer DEFAULT '0' NOT NULL,\n\
flags integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (triggerid)\n\
);\n\
CREATE INDEX triggers_1 ON triggers (status);\n\
CREATE INDEX triggers_2 ON triggers (value);\n\
CREATE INDEX triggers_3 ON triggers (templateid);\n\
CREATE TABLE trigger_depends (\n\
triggerdepid bigint  NOT NULL,\n\
triggerid_down bigint  NOT NULL REFERENCES triggers (triggerid) ON DELETE CASCADE,\n\
triggerid_up bigint  NOT NULL REFERENCES triggers (triggerid) ON DELETE CASCADE,\n\
PRIMARY KEY (triggerdepid)\n\
);\n\
CREATE UNIQUE INDEX trigger_depends_1 ON trigger_depends (triggerid_down,triggerid_up);\n\
CREATE INDEX trigger_depends_2 ON trigger_depends (triggerid_up);\n\
CREATE TABLE functions (\n\
functionid bigint  NOT NULL,\n\
itemid bigint  NOT NULL REFERENCES items (itemid) ON DELETE CASCADE,\n\
triggerid bigint  NOT NULL REFERENCES triggers (triggerid) ON DELETE CASCADE,\n\
function varchar(12) DEFAULT '' NOT NULL,\n\
parameter varchar(255) DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (functionid)\n\
);\n\
CREATE INDEX functions_1 ON functions (triggerid);\n\
CREATE INDEX functions_2 ON functions (itemid,function,parameter);\n\
CREATE TABLE graphs (\n\
graphid bigint  NOT NULL,\n\
name varchar(128) DEFAULT '' NOT NULL,\n\
width integer DEFAULT '900' NOT NULL,\n\
height integer DEFAULT '200' NOT NULL,\n\
yaxismin double(16,4) DEFAULT '0' NOT NULL,\n\
yaxismax double(16,4) DEFAULT '100' NOT NULL,\n\
templateid bigint  NULL REFERENCES graphs (graphid) ON DELETE CASCADE,\n\
show_work_period integer DEFAULT '1' NOT NULL,\n\
show_triggers integer DEFAULT '1' NOT NULL,\n\
graphtype integer DEFAULT '0' NOT NULL,\n\
show_legend integer DEFAULT '1' NOT NULL,\n\
show_3d integer DEFAULT '0' NOT NULL,\n\
percent_left double(16,4) DEFAULT '0' NOT NULL,\n\
percent_right double(16,4) DEFAULT '0' NOT NULL,\n\
ymin_type integer DEFAULT '0' NOT NULL,\n\
ymax_type integer DEFAULT '0' NOT NULL,\n\
ymin_itemid bigint  NULL REFERENCES items (itemid),\n\
ymax_itemid bigint  NULL REFERENCES items (itemid),\n\
flags integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (graphid)\n\
);\n\
CREATE INDEX graphs_1 ON graphs (name);\n\
CREATE INDEX graphs_2 ON graphs (templateid);\n\
CREATE INDEX graphs_3 ON graphs (ymin_itemid);\n\
CREATE INDEX graphs_4 ON graphs (ymax_itemid);\n\
CREATE TABLE graphs_items (\n\
gitemid bigint  NOT NULL,\n\
graphid bigint  NOT NULL REFERENCES graphs (graphid) ON DELETE CASCADE,\n\
itemid bigint  NOT NULL REFERENCES items (itemid) ON DELETE CASCADE,\n\
drawtype integer DEFAULT '0' NOT NULL,\n\
sortorder integer DEFAULT '0' NOT NULL,\n\
color varchar(6) DEFAULT '009600' NOT NULL,\n\
yaxisside integer DEFAULT '0' NOT NULL,\n\
calc_fnc integer DEFAULT '2' NOT NULL,\n\
type integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (gitemid)\n\
);\n\
CREATE INDEX graphs_items_1 ON graphs_items (itemid);\n\
CREATE INDEX graphs_items_2 ON graphs_items (graphid);\n\
CREATE TABLE graph_theme (\n\
graphthemeid bigint  NOT NULL,\n\
description varchar(64) DEFAULT '' NOT NULL,\n\
theme varchar(64) DEFAULT '' NOT NULL,\n\
backgroundcolor varchar(6) DEFAULT 'F0F0F0' NOT NULL,\n\
graphcolor varchar(6) DEFAULT 'FFFFFF' NOT NULL,\n\
graphbordercolor varchar(6) DEFAULT '222222' NOT NULL,\n\
gridcolor varchar(6) DEFAULT 'CCCCCC' NOT NULL,\n\
maingridcolor varchar(6) DEFAULT 'AAAAAA' NOT NULL,\n\
gridbordercolor varchar(6) DEFAULT '000000' NOT NULL,\n\
textcolor varchar(6) DEFAULT '202020' NOT NULL,\n\
highlightcolor varchar(6) DEFAULT 'AA4444' NOT NULL,\n\
leftpercentilecolor varchar(6) DEFAULT '11CC11' NOT NULL,\n\
rightpercentilecolor varchar(6) DEFAULT 'CC1111' NOT NULL,\n\
nonworktimecolor varchar(6) DEFAULT 'CCCCCC' NOT NULL,\n\
gridview integer DEFAULT 1 NOT NULL,\n\
legendview integer DEFAULT 1 NOT NULL,\n\
PRIMARY KEY (graphthemeid)\n\
);\n\
CREATE UNIQUE INDEX graph_theme_1 ON graph_theme (description);\n\
CREATE INDEX graph_theme_2 ON graph_theme (theme);\n\
CREATE TABLE globalmacro (\n\
globalmacroid bigint  NOT NULL,\n\
macro varchar(64) DEFAULT '' NOT NULL,\n\
value varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (globalmacroid)\n\
);\n\
CREATE UNIQUE INDEX globalmacro_1 ON globalmacro (macro);\n\
CREATE TABLE hostmacro (\n\
hostmacroid bigint  NOT NULL,\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
macro varchar(64) DEFAULT '' NOT NULL,\n\
value varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (hostmacroid)\n\
);\n\
CREATE UNIQUE INDEX hostmacro_1 ON hostmacro (hostid,macro);\n\
CREATE TABLE hosts_groups (\n\
hostgroupid bigint  NOT NULL,\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
groupid bigint  NOT NULL REFERENCES groups (groupid) ON DELETE CASCADE,\n\
PRIMARY KEY (hostgroupid)\n\
);\n\
CREATE UNIQUE INDEX hosts_groups_1 ON hosts_groups (hostid,groupid);\n\
CREATE INDEX hosts_groups_2 ON hosts_groups (groupid);\n\
CREATE TABLE hosts_templates (\n\
hosttemplateid bigint  NOT NULL,\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
templateid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
PRIMARY KEY (hosttemplateid)\n\
);\n\
CREATE UNIQUE INDEX hosts_templates_1 ON hosts_templates (hostid,templateid);\n\
CREATE INDEX hosts_templates_2 ON hosts_templates (templateid);\n\
CREATE TABLE items_applications (\n\
itemappid bigint  NOT NULL,\n\
applicationid bigint  NOT NULL REFERENCES applications (applicationid) ON DELETE CASCADE,\n\
itemid bigint  NOT NULL REFERENCES items (itemid) ON DELETE CASCADE,\n\
PRIMARY KEY (itemappid)\n\
);\n\
CREATE UNIQUE INDEX items_applications_1 ON items_applications (applicationid,itemid);\n\
CREATE INDEX items_applications_2 ON items_applications (itemid);\n\
CREATE TABLE mappings (\n\
mappingid bigint  NOT NULL,\n\
valuemapid bigint  NOT NULL REFERENCES valuemaps (valuemapid) ON DELETE CASCADE,\n\
value varchar(64) DEFAULT '' NOT NULL,\n\
newvalue varchar(64) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (mappingid)\n\
);\n\
CREATE INDEX mappings_1 ON mappings (valuemapid);\n\
CREATE TABLE media (\n\
mediaid bigint  NOT NULL,\n\
userid bigint  NOT NULL REFERENCES users (userid) ON DELETE CASCADE,\n\
mediatypeid bigint  NOT NULL REFERENCES media_type (mediatypeid) ON DELETE CASCADE,\n\
sendto varchar(100) DEFAULT '' NOT NULL,\n\
active integer DEFAULT '0' NOT NULL,\n\
severity integer DEFAULT '63' NOT NULL,\n\
period varchar(100) DEFAULT '1-7,00:00-24:00' NOT NULL,\n\
PRIMARY KEY (mediaid)\n\
);\n\
CREATE INDEX media_1 ON media (userid);\n\
CREATE INDEX media_2 ON media (mediatypeid);\n\
CREATE TABLE rights (\n\
rightid bigint  NOT NULL,\n\
groupid bigint  NOT NULL REFERENCES usrgrp (usrgrpid) ON DELETE CASCADE,\n\
permission integer DEFAULT '0' NOT NULL,\n\
id bigint  NOT NULL REFERENCES groups (groupid) ON DELETE CASCADE,\n\
PRIMARY KEY (rightid)\n\
);\n\
CREATE INDEX rights_1 ON rights (groupid);\n\
CREATE INDEX rights_2 ON rights (id);\n\
CREATE TABLE services (\n\
serviceid bigint  NOT NULL,\n\
name varchar(128) DEFAULT '' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
algorithm integer DEFAULT '0' NOT NULL,\n\
triggerid bigint  NULL REFERENCES triggers (triggerid) ON DELETE CASCADE,\n\
showsla integer DEFAULT '0' NOT NULL,\n\
goodsla double(16,4) DEFAULT '99.9' NOT NULL,\n\
sortorder integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (serviceid)\n\
);\n\
CREATE INDEX services_1 ON services (triggerid);\n\
CREATE TABLE services_links (\n\
linkid bigint  NOT NULL,\n\
serviceupid bigint  NOT NULL REFERENCES services (serviceid) ON DELETE CASCADE,\n\
servicedownid bigint  NOT NULL REFERENCES services (serviceid) ON DELETE CASCADE,\n\
soft integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (linkid)\n\
);\n\
CREATE INDEX services_links_1 ON services_links (servicedownid);\n\
CREATE UNIQUE INDEX services_links_2 ON services_links (serviceupid,servicedownid);\n\
CREATE TABLE services_times (\n\
timeid bigint  NOT NULL,\n\
serviceid bigint  NOT NULL REFERENCES services (serviceid) ON DELETE CASCADE,\n\
type integer DEFAULT '0' NOT NULL,\n\
ts_from integer DEFAULT '0' NOT NULL,\n\
ts_to integer DEFAULT '0' NOT NULL,\n\
note varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (timeid)\n\
);\n\
CREATE INDEX services_times_1 ON services_times (serviceid,type,ts_from,ts_to);\n\
CREATE TABLE icon_map (\n\
iconmapid bigint  NOT NULL,\n\
name varchar(64) DEFAULT '' NOT NULL,\n\
default_iconid bigint  NOT NULL REFERENCES images (imageid),\n\
PRIMARY KEY (iconmapid)\n\
);\n\
CREATE UNIQUE INDEX icon_map_1 ON icon_map (name);\n\
CREATE INDEX icon_map_2 ON icon_map (default_iconid);\n\
CREATE TABLE icon_mapping (\n\
iconmappingid bigint  NOT NULL,\n\
iconmapid bigint  NOT NULL REFERENCES icon_map (iconmapid) ON DELETE CASCADE,\n\
iconid bigint  NOT NULL REFERENCES images (imageid),\n\
inventory_link integer DEFAULT '0' NOT NULL,\n\
expression varchar(64) DEFAULT '' NOT NULL,\n\
sortorder integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (iconmappingid)\n\
);\n\
CREATE INDEX icon_mapping_1 ON icon_mapping (iconmapid);\n\
CREATE INDEX icon_mapping_2 ON icon_mapping (iconid);\n\
CREATE TABLE sysmaps (\n\
sysmapid bigint  NOT NULL,\n\
name varchar(128) DEFAULT '' NOT NULL,\n\
width integer DEFAULT '600' NOT NULL,\n\
height integer DEFAULT '400' NOT NULL,\n\
backgroundid bigint  NULL REFERENCES images (imageid),\n\
label_type integer DEFAULT '2' NOT NULL,\n\
label_location integer DEFAULT '0' NOT NULL,\n\
highlight integer DEFAULT '1' NOT NULL,\n\
expandproblem integer DEFAULT '1' NOT NULL,\n\
markelements integer DEFAULT '0' NOT NULL,\n\
show_unack integer DEFAULT '0' NOT NULL,\n\
grid_size integer DEFAULT '50' NOT NULL,\n\
grid_show integer DEFAULT '1' NOT NULL,\n\
grid_align integer DEFAULT '1' NOT NULL,\n\
label_format integer DEFAULT '0' NOT NULL,\n\
label_type_host integer DEFAULT '2' NOT NULL,\n\
label_type_hostgroup integer DEFAULT '2' NOT NULL,\n\
label_type_trigger integer DEFAULT '2' NOT NULL,\n\
label_type_map integer DEFAULT '2' NOT NULL,\n\
label_type_image integer DEFAULT '2' NOT NULL,\n\
label_string_host varchar(255) DEFAULT '' NOT NULL,\n\
label_string_hostgroup varchar(255) DEFAULT '' NOT NULL,\n\
label_string_trigger varchar(255) DEFAULT '' NOT NULL,\n\
label_string_map varchar(255) DEFAULT '' NOT NULL,\n\
label_string_image varchar(255) DEFAULT '' NOT NULL,\n\
iconmapid bigint  NULL REFERENCES icon_map (iconmapid),\n\
expand_macros integer DEFAULT '0' NOT NULL,\n\
severity_min integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (sysmapid)\n\
);\n\
CREATE UNIQUE INDEX sysmaps_1 ON sysmaps (name);\n\
CREATE INDEX sysmaps_2 ON sysmaps (backgroundid);\n\
CREATE INDEX sysmaps_3 ON sysmaps (iconmapid);\n\
CREATE TABLE sysmaps_elements (\n\
selementid bigint  NOT NULL,\n\
sysmapid bigint  NOT NULL REFERENCES sysmaps (sysmapid) ON DELETE CASCADE,\n\
elementid bigint DEFAULT '0' NOT NULL,\n\
elementtype integer DEFAULT '0' NOT NULL,\n\
iconid_off bigint  NULL REFERENCES images (imageid),\n\
iconid_on bigint  NULL REFERENCES images (imageid),\n\
label varchar(2048) DEFAULT '' NOT NULL,\n\
label_location integer DEFAULT '-1' NOT NULL,\n\
x integer DEFAULT '0' NOT NULL,\n\
y integer DEFAULT '0' NOT NULL,\n\
iconid_disabled bigint  NULL REFERENCES images (imageid),\n\
iconid_maintenance bigint  NULL REFERENCES images (imageid),\n\
elementsubtype integer DEFAULT '0' NOT NULL,\n\
areatype integer DEFAULT '0' NOT NULL,\n\
width integer DEFAULT '200' NOT NULL,\n\
height integer DEFAULT '200' NOT NULL,\n\
viewtype integer DEFAULT '0' NOT NULL,\n\
use_iconmap integer DEFAULT '1' NOT NULL,\n\
application varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (selementid)\n\
);\n\
CREATE INDEX sysmaps_elements_1 ON sysmaps_elements (sysmapid);\n\
CREATE INDEX sysmaps_elements_2 ON sysmaps_elements (iconid_off);\n\
CREATE INDEX sysmaps_elements_3 ON sysmaps_elements (iconid_on);\n\
CREATE INDEX sysmaps_elements_4 ON sysmaps_elements (iconid_disabled);\n\
CREATE INDEX sysmaps_elements_5 ON sysmaps_elements (iconid_maintenance);\n\
CREATE TABLE sysmaps_links (\n\
linkid bigint  NOT NULL,\n\
sysmapid bigint  NOT NULL REFERENCES sysmaps (sysmapid) ON DELETE CASCADE,\n\
selementid1 bigint  NOT NULL REFERENCES sysmaps_elements (selementid) ON DELETE CASCADE,\n\
selementid2 bigint  NOT NULL REFERENCES sysmaps_elements (selementid) ON DELETE CASCADE,\n\
drawtype integer DEFAULT '0' NOT NULL,\n\
color varchar(6) DEFAULT '000000' NOT NULL,\n\
label varchar(2048) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (linkid)\n\
);\n\
CREATE INDEX sysmaps_links_1 ON sysmaps_links (sysmapid);\n\
CREATE INDEX sysmaps_links_2 ON sysmaps_links (selementid1);\n\
CREATE INDEX sysmaps_links_3 ON sysmaps_links (selementid2);\n\
CREATE TABLE sysmaps_link_triggers (\n\
linktriggerid bigint  NOT NULL,\n\
linkid bigint  NOT NULL REFERENCES sysmaps_links (linkid) ON DELETE CASCADE,\n\
triggerid bigint  NOT NULL REFERENCES triggers (triggerid) ON DELETE CASCADE,\n\
drawtype integer DEFAULT '0' NOT NULL,\n\
color varchar(6) DEFAULT '000000' NOT NULL,\n\
PRIMARY KEY (linktriggerid)\n\
);\n\
CREATE UNIQUE INDEX sysmaps_link_triggers_1 ON sysmaps_link_triggers (linkid,triggerid);\n\
CREATE INDEX sysmaps_link_triggers_2 ON sysmaps_link_triggers (triggerid);\n\
CREATE TABLE sysmap_element_url (\n\
sysmapelementurlid bigint  NOT NULL,\n\
selementid bigint  NOT NULL REFERENCES sysmaps_elements (selementid) ON DELETE CASCADE,\n\
name varchar(255)  NOT NULL,\n\
url varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (sysmapelementurlid)\n\
);\n\
CREATE UNIQUE INDEX sysmap_element_url_1 ON sysmap_element_url (selementid,name);\n\
CREATE TABLE sysmap_url (\n\
sysmapurlid bigint  NOT NULL,\n\
sysmapid bigint  NOT NULL REFERENCES sysmaps (sysmapid) ON DELETE CASCADE,\n\
name varchar(255)  NOT NULL,\n\
url varchar(255) DEFAULT '' NOT NULL,\n\
elementtype integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (sysmapurlid)\n\
);\n\
CREATE UNIQUE INDEX sysmap_url_1 ON sysmap_url (sysmapid,name);\n\
CREATE TABLE maintenances_hosts (\n\
maintenance_hostid bigint  NOT NULL,\n\
maintenanceid bigint  NOT NULL REFERENCES maintenances (maintenanceid) ON DELETE CASCADE,\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
PRIMARY KEY (maintenance_hostid)\n\
);\n\
CREATE UNIQUE INDEX maintenances_hosts_1 ON maintenances_hosts (maintenanceid,hostid);\n\
CREATE INDEX maintenances_hosts_2 ON maintenances_hosts (hostid);\n\
CREATE TABLE maintenances_groups (\n\
maintenance_groupid bigint  NOT NULL,\n\
maintenanceid bigint  NOT NULL REFERENCES maintenances (maintenanceid) ON DELETE CASCADE,\n\
groupid bigint  NOT NULL REFERENCES groups (groupid) ON DELETE CASCADE,\n\
PRIMARY KEY (maintenance_groupid)\n\
);\n\
CREATE UNIQUE INDEX maintenances_groups_1 ON maintenances_groups (maintenanceid,groupid);\n\
CREATE INDEX maintenances_groups_2 ON maintenances_groups (groupid);\n\
CREATE TABLE timeperiods (\n\
timeperiodid bigint  NOT NULL,\n\
timeperiod_type integer DEFAULT '0' NOT NULL,\n\
every integer DEFAULT '1' NOT NULL,\n\
month integer DEFAULT '0' NOT NULL,\n\
dayofweek integer DEFAULT '0' NOT NULL,\n\
day integer DEFAULT '0' NOT NULL,\n\
start_time integer DEFAULT '0' NOT NULL,\n\
period integer DEFAULT '0' NOT NULL,\n\
start_date integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (timeperiodid)\n\
);\n\
CREATE TABLE maintenances_windows (\n\
maintenance_timeperiodid bigint  NOT NULL,\n\
maintenanceid bigint  NOT NULL REFERENCES maintenances (maintenanceid) ON DELETE CASCADE,\n\
timeperiodid bigint  NOT NULL REFERENCES timeperiods (timeperiodid) ON DELETE CASCADE,\n\
PRIMARY KEY (maintenance_timeperiodid)\n\
);\n\
CREATE UNIQUE INDEX maintenances_windows_1 ON maintenances_windows (maintenanceid,timeperiodid);\n\
CREATE INDEX maintenances_windows_2 ON maintenances_windows (timeperiodid);\n\
CREATE TABLE regexps (\n\
regexpid bigint  NOT NULL,\n\
name varchar(128) DEFAULT '' NOT NULL,\n\
test_string text DEFAULT '' NOT NULL,\n\
PRIMARY KEY (regexpid)\n\
);\n\
CREATE UNIQUE INDEX regexps_1 ON regexps (name);\n\
CREATE TABLE expressions (\n\
expressionid bigint  NOT NULL,\n\
regexpid bigint  NOT NULL REFERENCES regexps (regexpid) ON DELETE CASCADE,\n\
expression varchar(255) DEFAULT '' NOT NULL,\n\
expression_type integer DEFAULT '0' NOT NULL,\n\
exp_delimiter varchar(1) DEFAULT '' NOT NULL,\n\
case_sensitive integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (expressionid)\n\
);\n\
CREATE INDEX expressions_1 ON expressions (regexpid);\n\
CREATE TABLE ids (\n\
table_name varchar(64) DEFAULT '' NOT NULL,\n\
field_name varchar(64) DEFAULT '' NOT NULL,\n\
nextid bigint  NOT NULL,\n\
PRIMARY KEY (table_name,field_name)\n\
);\n\
CREATE TABLE alerts (\n\
alertid bigint  NOT NULL,\n\
actionid bigint  NOT NULL REFERENCES actions (actionid) ON DELETE CASCADE,\n\
eventid bigint  NOT NULL REFERENCES events (eventid) ON DELETE CASCADE,\n\
userid bigint  NULL REFERENCES users (userid) ON DELETE CASCADE,\n\
clock integer DEFAULT '0' NOT NULL,\n\
mediatypeid bigint  NULL REFERENCES media_type (mediatypeid) ON DELETE CASCADE,\n\
sendto varchar(100) DEFAULT '' NOT NULL,\n\
subject varchar(255) DEFAULT '' NOT NULL,\n\
message text DEFAULT '' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
retries integer DEFAULT '0' NOT NULL,\n\
error varchar(128) DEFAULT '' NOT NULL,\n\
esc_step integer DEFAULT '0' NOT NULL,\n\
alerttype integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (alertid)\n\
);\n\
CREATE INDEX alerts_1 ON alerts (actionid);\n\
CREATE INDEX alerts_2 ON alerts (clock);\n\
CREATE INDEX alerts_3 ON alerts (eventid);\n\
CREATE INDEX alerts_4 ON alerts (status,retries);\n\
CREATE INDEX alerts_5 ON alerts (mediatypeid);\n\
CREATE INDEX alerts_6 ON alerts (userid);\n\
CREATE TABLE history (\n\
itemid bigint  NOT NULL,\n\
clock integer DEFAULT '0' NOT NULL,\n\
value double(16,4) DEFAULT '0.0000' NOT NULL,\n\
ns integer DEFAULT '0' NOT NULL\n\
);\n\
CREATE INDEX history_1 ON history (itemid,clock);\n\
CREATE TABLE history_uint (\n\
itemid bigint  NOT NULL,\n\
clock integer DEFAULT '0' NOT NULL,\n\
value bigint DEFAULT '0' NOT NULL,\n\
ns integer DEFAULT '0' NOT NULL\n\
);\n\
CREATE INDEX history_uint_1 ON history_uint (itemid,clock);\n\
CREATE TABLE history_str (\n\
itemid bigint  NOT NULL,\n\
clock integer DEFAULT '0' NOT NULL,\n\
value varchar(255) DEFAULT '' NOT NULL,\n\
ns integer DEFAULT '0' NOT NULL\n\
);\n\
CREATE INDEX history_str_1 ON history_str (itemid,clock);\n\
CREATE TABLE history_log (\n\
id bigint  NOT NULL,\n\
itemid bigint  NOT NULL,\n\
clock integer DEFAULT '0' NOT NULL,\n\
timestamp integer DEFAULT '0' NOT NULL,\n\
source varchar(64) DEFAULT '' NOT NULL,\n\
severity integer DEFAULT '0' NOT NULL,\n\
value text DEFAULT '' NOT NULL,\n\
logeventid integer DEFAULT '0' NOT NULL,\n\
ns integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (id)\n\
);\n\
CREATE INDEX history_log_1 ON history_log (itemid,clock);\n\
CREATE UNIQUE INDEX history_log_2 ON history_log (itemid,id);\n\
CREATE TABLE history_text (\n\
id bigint  NOT NULL,\n\
itemid bigint  NOT NULL,\n\
clock integer DEFAULT '0' NOT NULL,\n\
value text DEFAULT '' NOT NULL,\n\
ns integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (id)\n\
);\n\
CREATE INDEX history_text_1 ON history_text (itemid,clock);\n\
CREATE UNIQUE INDEX history_text_2 ON history_text (itemid,id);\n\
CREATE TABLE proxy_history (\n\
id integer  NOT NULL PRIMARY KEY AUTOINCREMENT,\n\
itemid bigint  NOT NULL,\n\
clock integer DEFAULT '0' NOT NULL,\n\
timestamp integer DEFAULT '0' NOT NULL,\n\
source varchar(64) DEFAULT '' NOT NULL,\n\
severity integer DEFAULT '0' NOT NULL,\n\
value text DEFAULT '' NOT NULL,\n\
logeventid integer DEFAULT '0' NOT NULL,\n\
ns integer DEFAULT '0' NOT NULL,\n\
state integer DEFAULT '0' NOT NULL\n\
);\n\
CREATE INDEX proxy_history_1 ON proxy_history (clock);\n\
CREATE TABLE proxy_dhistory (\n\
id integer  NOT NULL PRIMARY KEY AUTOINCREMENT,\n\
clock integer DEFAULT '0' NOT NULL,\n\
druleid bigint  NOT NULL,\n\
type integer DEFAULT '0' NOT NULL,\n\
ip varchar(39) DEFAULT '' NOT NULL,\n\
port integer DEFAULT '0' NOT NULL,\n\
key_ varchar(255) DEFAULT '' NOT NULL,\n\
value varchar(255) DEFAULT '' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
dcheckid bigint  NULL,\n\
dns varchar(64) DEFAULT '' NOT NULL\n\
);\n\
CREATE INDEX proxy_dhistory_1 ON proxy_dhistory (clock);\n\
CREATE TABLE events (\n\
eventid bigint  NOT NULL,\n\
source integer DEFAULT '0' NOT NULL,\n\
object integer DEFAULT '0' NOT NULL,\n\
objectid bigint DEFAULT '0' NOT NULL,\n\
clock integer DEFAULT '0' NOT NULL,\n\
value integer DEFAULT '0' NOT NULL,\n\
acknowledged integer DEFAULT '0' NOT NULL,\n\
ns integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (eventid)\n\
);\n\
CREATE INDEX events_1 ON events (source,object,objectid,clock);\n\
CREATE INDEX events_2 ON events (source,object,clock);\n\
CREATE TABLE trends (\n\
itemid bigint  NOT NULL,\n\
clock integer DEFAULT '0' NOT NULL,\n\
num integer DEFAULT '0' NOT NULL,\n\
value_min double(16,4) DEFAULT '0.0000' NOT NULL,\n\
value_avg double(16,4) DEFAULT '0.0000' NOT NULL,\n\
value_max double(16,4) DEFAULT '0.0000' NOT NULL,\n\
PRIMARY KEY (itemid,clock)\n\
);\n\
CREATE TABLE trends_uint (\n\
itemid bigint  NOT NULL,\n\
clock integer DEFAULT '0' NOT NULL,\n\
num integer DEFAULT '0' NOT NULL,\n\
value_min bigint DEFAULT '0' NOT NULL,\n\
value_avg bigint DEFAULT '0' NOT NULL,\n\
value_max bigint DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (itemid,clock)\n\
);\n\
CREATE TABLE acknowledges (\n\
acknowledgeid bigint  NOT NULL,\n\
userid bigint  NOT NULL REFERENCES users (userid) ON DELETE CASCADE,\n\
eventid bigint  NOT NULL REFERENCES events (eventid) ON DELETE CASCADE,\n\
clock integer DEFAULT '0' NOT NULL,\n\
message varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (acknowledgeid)\n\
);\n\
CREATE INDEX acknowledges_1 ON acknowledges (userid);\n\
CREATE INDEX acknowledges_2 ON acknowledges (eventid);\n\
CREATE INDEX acknowledges_3 ON acknowledges (clock);\n\
CREATE TABLE auditlog (\n\
auditid bigint  NOT NULL,\n\
userid bigint  NOT NULL REFERENCES users (userid) ON DELETE CASCADE,\n\
clock integer DEFAULT '0' NOT NULL,\n\
action integer DEFAULT '0' NOT NULL,\n\
resourcetype integer DEFAULT '0' NOT NULL,\n\
details varchar(128)  DEFAULT '0' NOT NULL,\n\
ip varchar(39) DEFAULT '' NOT NULL,\n\
resourceid bigint DEFAULT '0' NOT NULL,\n\
resourcename varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (auditid)\n\
);\n\
CREATE INDEX auditlog_1 ON auditlog (userid,clock);\n\
CREATE INDEX auditlog_2 ON auditlog (clock);\n\
CREATE TABLE auditlog_details (\n\
auditdetailid bigint  NOT NULL,\n\
auditid bigint  NOT NULL REFERENCES auditlog (auditid) ON DELETE CASCADE,\n\
table_name varchar(64) DEFAULT '' NOT NULL,\n\
field_name varchar(64) DEFAULT '' NOT NULL,\n\
oldvalue text DEFAULT '' NOT NULL,\n\
newvalue text DEFAULT '' NOT NULL,\n\
PRIMARY KEY (auditdetailid)\n\
);\n\
CREATE INDEX auditlog_details_1 ON auditlog_details (auditid);\n\
CREATE TABLE service_alarms (\n\
servicealarmid bigint  NOT NULL,\n\
serviceid bigint  NOT NULL REFERENCES services (serviceid) ON DELETE CASCADE,\n\
clock integer DEFAULT '0' NOT NULL,\n\
value integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (servicealarmid)\n\
);\n\
CREATE INDEX service_alarms_1 ON service_alarms (serviceid,clock);\n\
CREATE INDEX service_alarms_2 ON service_alarms (clock);\n\
CREATE TABLE autoreg_host (\n\
autoreg_hostid bigint  NOT NULL,\n\
proxy_hostid bigint  NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
host varchar(64) DEFAULT '' NOT NULL,\n\
listen_ip varchar(39) DEFAULT '' NOT NULL,\n\
listen_port integer DEFAULT '0' NOT NULL,\n\
listen_dns varchar(64) DEFAULT '' NOT NULL,\n\
host_metadata varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (autoreg_hostid)\n\
);\n\
CREATE INDEX autoreg_host_1 ON autoreg_host (proxy_hostid,host);\n\
CREATE TABLE proxy_autoreg_host (\n\
id integer  NOT NULL PRIMARY KEY AUTOINCREMENT,\n\
clock integer DEFAULT '0' NOT NULL,\n\
host varchar(64) DEFAULT '' NOT NULL,\n\
listen_ip varchar(39) DEFAULT '' NOT NULL,\n\
listen_port integer DEFAULT '0' NOT NULL,\n\
listen_dns varchar(64) DEFAULT '' NOT NULL,\n\
host_metadata varchar(255) DEFAULT '' NOT NULL\n\
);\n\
CREATE INDEX proxy_autoreg_host_1 ON proxy_autoreg_host (clock);\n\
CREATE TABLE dhosts (\n\
dhostid bigint  NOT NULL,\n\
druleid bigint  NOT NULL REFERENCES drules (druleid) ON DELETE CASCADE,\n\
status integer DEFAULT '0' NOT NULL,\n\
lastup integer DEFAULT '0' NOT NULL,\n\
lastdown integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (dhostid)\n\
);\n\
CREATE INDEX dhosts_1 ON dhosts (druleid);\n\
CREATE TABLE dservices (\n\
dserviceid bigint  NOT NULL,\n\
dhostid bigint  NOT NULL REFERENCES dhosts (dhostid) ON DELETE CASCADE,\n\
type integer DEFAULT '0' NOT NULL,\n\
key_ varchar(255) DEFAULT '' NOT NULL,\n\
value varchar(255) DEFAULT '' NOT NULL,\n\
port integer DEFAULT '0' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
lastup integer DEFAULT '0' NOT NULL,\n\
lastdown integer DEFAULT '0' NOT NULL,\n\
dcheckid bigint  NOT NULL REFERENCES dchecks (dcheckid) ON DELETE CASCADE,\n\
ip varchar(39) DEFAULT '' NOT NULL,\n\
dns varchar(64) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (dserviceid)\n\
);\n\
CREATE UNIQUE INDEX dservices_1 ON dservices (dcheckid,type,key_,ip,port);\n\
CREATE INDEX dservices_2 ON dservices (dhostid);\n\
CREATE TABLE escalations (\n\
escalationid bigint  NOT NULL,\n\
actionid bigint  NOT NULL,\n\
triggerid bigint  NULL,\n\
eventid bigint  NULL,\n\
r_eventid bigint  NULL,\n\
nextcheck integer DEFAULT '0' NOT NULL,\n\
esc_step integer DEFAULT '0' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
itemid bigint  NULL,\n\
PRIMARY KEY (escalationid)\n\
);\n\
CREATE UNIQUE INDEX escalations_1 ON escalations (actionid,triggerid,itemid,escalationid);\n\
CREATE TABLE globalvars (\n\
globalvarid bigint  NOT NULL,\n\
snmp_lastsize integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (globalvarid)\n\
);\n\
CREATE TABLE graph_discovery (\n\
graphid bigint  NOT NULL REFERENCES graphs (graphid) ON DELETE CASCADE,\n\
parent_graphid bigint  NOT NULL REFERENCES graphs (graphid),\n\
PRIMARY KEY (graphid)\n\
);\n\
CREATE INDEX graph_discovery_1 ON graph_discovery (parent_graphid);\n\
CREATE TABLE host_inventory (\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
inventory_mode integer DEFAULT '0' NOT NULL,\n\
type varchar(64) DEFAULT '' NOT NULL,\n\
type_full varchar(64) DEFAULT '' NOT NULL,\n\
name varchar(64) DEFAULT '' NOT NULL,\n\
alias varchar(64) DEFAULT '' NOT NULL,\n\
os varchar(64) DEFAULT '' NOT NULL,\n\
os_full varchar(255) DEFAULT '' NOT NULL,\n\
os_short varchar(64) DEFAULT '' NOT NULL,\n\
serialno_a varchar(64) DEFAULT '' NOT NULL,\n\
serialno_b varchar(64) DEFAULT '' NOT NULL,\n\
tag varchar(64) DEFAULT '' NOT NULL,\n\
asset_tag varchar(64) DEFAULT '' NOT NULL,\n\
macaddress_a varchar(64) DEFAULT '' NOT NULL,\n\
macaddress_b varchar(64) DEFAULT '' NOT NULL,\n\
hardware varchar(255) DEFAULT '' NOT NULL,\n\
hardware_full text DEFAULT '' NOT NULL,\n\
software varchar(255) DEFAULT '' NOT NULL,\n\
software_full text DEFAULT '' NOT NULL,\n\
software_app_a varchar(64) DEFAULT '' NOT NULL,\n\
software_app_b varchar(64) DEFAULT '' NOT NULL,\n\
software_app_c varchar(64) DEFAULT '' NOT NULL,\n\
software_app_d varchar(64) DEFAULT '' NOT NULL,\n\
software_app_e varchar(64) DEFAULT '' NOT NULL,\n\
contact text DEFAULT '' NOT NULL,\n\
location text DEFAULT '' NOT NULL,\n\
location_lat varchar(16) DEFAULT '' NOT NULL,\n\
location_lon varchar(16) DEFAULT '' NOT NULL,\n\
notes text DEFAULT '' NOT NULL,\n\
chassis varchar(64) DEFAULT '' NOT NULL,\n\
model varchar(64) DEFAULT '' NOT NULL,\n\
hw_arch varchar(32) DEFAULT '' NOT NULL,\n\
vendor varchar(64) DEFAULT '' NOT NULL,\n\
contract_number varchar(64) DEFAULT '' NOT NULL,\n\
installer_name varchar(64) DEFAULT '' NOT NULL,\n\
deployment_status varchar(64) DEFAULT '' NOT NULL,\n\
url_a varchar(255) DEFAULT '' NOT NULL,\n\
url_b varchar(255) DEFAULT '' NOT NULL,\n\
url_c varchar(255) DEFAULT '' NOT NULL,\n\
host_networks text DEFAULT '' NOT NULL,\n\
host_netmask varchar(39) DEFAULT '' NOT NULL,\n\
host_router varchar(39) DEFAULT '' NOT NULL,\n\
oob_ip varchar(39) DEFAULT '' NOT NULL,\n\
oob_netmask varchar(39) DEFAULT '' NOT NULL,\n\
oob_router varchar(39) DEFAULT '' NOT NULL,\n\
date_hw_purchase varchar(64) DEFAULT '' NOT NULL,\n\
date_hw_install varchar(64) DEFAULT '' NOT NULL,\n\
date_hw_expiry varchar(64) DEFAULT '' NOT NULL,\n\
date_hw_decomm varchar(64) DEFAULT '' NOT NULL,\n\
site_address_a varchar(128) DEFAULT '' NOT NULL,\n\
site_address_b varchar(128) DEFAULT '' NOT NULL,\n\
site_address_c varchar(128) DEFAULT '' NOT NULL,\n\
site_city varchar(128) DEFAULT '' NOT NULL,\n\
site_state varchar(64) DEFAULT '' NOT NULL,\n\
site_country varchar(64) DEFAULT '' NOT NULL,\n\
site_zip varchar(64) DEFAULT '' NOT NULL,\n\
site_rack varchar(128) DEFAULT '' NOT NULL,\n\
site_notes text DEFAULT '' NOT NULL,\n\
poc_1_name varchar(128) DEFAULT '' NOT NULL,\n\
poc_1_email varchar(128) DEFAULT '' NOT NULL,\n\
poc_1_phone_a varchar(64) DEFAULT '' NOT NULL,\n\
poc_1_phone_b varchar(64) DEFAULT '' NOT NULL,\n\
poc_1_cell varchar(64) DEFAULT '' NOT NULL,\n\
poc_1_screen varchar(64) DEFAULT '' NOT NULL,\n\
poc_1_notes text DEFAULT '' NOT NULL,\n\
poc_2_name varchar(128) DEFAULT '' NOT NULL,\n\
poc_2_email varchar(128) DEFAULT '' NOT NULL,\n\
poc_2_phone_a varchar(64) DEFAULT '' NOT NULL,\n\
poc_2_phone_b varchar(64) DEFAULT '' NOT NULL,\n\
poc_2_cell varchar(64) DEFAULT '' NOT NULL,\n\
poc_2_screen varchar(64) DEFAULT '' NOT NULL,\n\
poc_2_notes text DEFAULT '' NOT NULL,\n\
PRIMARY KEY (hostid)\n\
);\n\
CREATE TABLE housekeeper (\n\
housekeeperid bigint  NOT NULL,\n\
tablename varchar(64) DEFAULT '' NOT NULL,\n\
field varchar(64) DEFAULT '' NOT NULL,\n\
value bigint  NOT NULL,\n\
PRIMARY KEY (housekeeperid)\n\
);\n\
CREATE TABLE images (\n\
imageid bigint  NOT NULL,\n\
imagetype integer DEFAULT '0' NOT NULL,\n\
name varchar(64) DEFAULT '0' NOT NULL,\n\
image longblob DEFAULT '' NOT NULL,\n\
PRIMARY KEY (imageid)\n\
);\n\
CREATE UNIQUE INDEX images_1 ON images (name);\n\
CREATE TABLE item_discovery (\n\
itemdiscoveryid bigint  NOT NULL,\n\
itemid bigint  NOT NULL REFERENCES items (itemid) ON DELETE CASCADE,\n\
parent_itemid bigint  NOT NULL REFERENCES items (itemid) ON DELETE CASCADE,\n\
key_ varchar(255) DEFAULT '' NOT NULL,\n\
lastcheck integer DEFAULT '0' NOT NULL,\n\
ts_delete integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (itemdiscoveryid)\n\
);\n\
CREATE UNIQUE INDEX item_discovery_1 ON item_discovery (itemid,parent_itemid);\n\
CREATE INDEX item_discovery_2 ON item_discovery (parent_itemid);\n\
CREATE TABLE host_discovery (\n\
hostid bigint  NOT NULL REFERENCES hosts (hostid) ON DELETE CASCADE,\n\
parent_hostid bigint  NULL REFERENCES hosts (hostid),\n\
parent_itemid bigint  NULL REFERENCES items (itemid),\n\
host varchar(64) DEFAULT '' NOT NULL,\n\
lastcheck integer DEFAULT '0' NOT NULL,\n\
ts_delete integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (hostid)\n\
);\n\
CREATE TABLE interface_discovery (\n\
interfaceid bigint  NOT NULL REFERENCES interface (interfaceid) ON DELETE CASCADE,\n\
parent_interfaceid bigint  NOT NULL REFERENCES interface (interfaceid) ON DELETE CASCADE,\n\
PRIMARY KEY (interfaceid)\n\
);\n\
CREATE TABLE profiles (\n\
profileid bigint  NOT NULL,\n\
userid bigint  NOT NULL REFERENCES users (userid) ON DELETE CASCADE,\n\
idx varchar(96) DEFAULT '' NOT NULL,\n\
idx2 bigint DEFAULT '0' NOT NULL,\n\
value_id bigint DEFAULT '0' NOT NULL,\n\
value_int integer DEFAULT '0' NOT NULL,\n\
value_str varchar(255) DEFAULT '' NOT NULL,\n\
source varchar(96) DEFAULT '' NOT NULL,\n\
type integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (profileid)\n\
);\n\
CREATE INDEX profiles_1 ON profiles (userid,idx,idx2);\n\
CREATE INDEX profiles_2 ON profiles (userid,profileid);\n\
CREATE TABLE sessions (\n\
sessionid varchar(32) DEFAULT '' NOT NULL,\n\
userid bigint  NOT NULL REFERENCES users (userid) ON DELETE CASCADE,\n\
lastaccess integer DEFAULT '0' NOT NULL,\n\
status integer DEFAULT '0' NOT NULL,\n\
PRIMARY KEY (sessionid)\n\
);\n\
CREATE INDEX sessions_1 ON sessions (userid,status);\n\
CREATE TABLE trigger_discovery (\n\
triggerid bigint  NOT NULL REFERENCES triggers (triggerid) ON DELETE CASCADE,\n\
parent_triggerid bigint  NOT NULL REFERENCES triggers (triggerid),\n\
PRIMARY KEY (triggerid)\n\
);\n\
CREATE INDEX trigger_discovery_1 ON trigger_discovery (parent_triggerid);\n\
CREATE TABLE user_history (\n\
userhistoryid bigint  NOT NULL,\n\
userid bigint  NOT NULL REFERENCES users (userid) ON DELETE CASCADE,\n\
title1 varchar(255) DEFAULT '' NOT NULL,\n\
url1 varchar(255) DEFAULT '' NOT NULL,\n\
title2 varchar(255) DEFAULT '' NOT NULL,\n\
url2 varchar(255) DEFAULT '' NOT NULL,\n\
title3 varchar(255) DEFAULT '' NOT NULL,\n\
url3 varchar(255) DEFAULT '' NOT NULL,\n\
title4 varchar(255) DEFAULT '' NOT NULL,\n\
url4 varchar(255) DEFAULT '' NOT NULL,\n\
title5 varchar(255) DEFAULT '' NOT NULL,\n\
url5 varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (userhistoryid)\n\
);\n\
CREATE UNIQUE INDEX user_history_1 ON user_history (userid);\n\
CREATE TABLE application_template (\n\
application_templateid bigint  NOT NULL,\n\
applicationid bigint  NOT NULL REFERENCES applications (applicationid) ON DELETE CASCADE,\n\
templateid bigint  NOT NULL REFERENCES applications (applicationid) ON DELETE CASCADE,\n\
PRIMARY KEY (application_templateid)\n\
);\n\
CREATE UNIQUE INDEX application_template_1 ON application_template (applicationid,templateid);\n\
CREATE INDEX application_template_2 ON application_template (templateid);\n\
CREATE TABLE item_condition (\n\
item_conditionid bigint  NOT NULL,\n\
itemid bigint  NOT NULL REFERENCES items (itemid) ON DELETE CASCADE,\n\
operator integer DEFAULT '8' NOT NULL,\n\
macro varchar(64) DEFAULT '' NOT NULL,\n\
value varchar(255) DEFAULT '' NOT NULL,\n\
PRIMARY KEY (item_conditionid)\n\
);\n\
CREATE INDEX item_condition_1 ON item_condition (itemid);\n\
CREATE TABLE dbversion (\n\
mandatory integer DEFAULT '0' NOT NULL,\n\
optional integer DEFAULT '0' NOT NULL\n\
);\n\
INSERT INTO dbversion VALUES ('2040000','2040000');\n\
";
const char	*const db_schema_fkeys[] = {
	NULL
};
#else	/* HAVE_SQLITE3 */
const char	*const db_schema = NULL;
#endif	/* not HAVE_SQLITE3 */
