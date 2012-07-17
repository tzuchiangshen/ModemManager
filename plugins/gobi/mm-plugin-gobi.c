/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details:
 *
 * Copyright (C) 2008 - 2009 Novell, Inc.
 * Copyright (C) 2011 Red Hat, Inc.
 */

#include <string.h>
#include <gmodule.h>

#include <libmm-common.h>

#include "mm-plugin-gobi.h"
#include "mm-broadband-modem-qmi.h"
#include "mm-broadband-modem-gobi.h"
#include "mm-log.h"

G_DEFINE_TYPE (MMPluginGobi, mm_plugin_gobi, MM_TYPE_PLUGIN)

int mm_plugin_major_version = MM_PLUGIN_MAJOR_VERSION;
int mm_plugin_minor_version = MM_PLUGIN_MINOR_VERSION;

/*****************************************************************************/

static MMBaseModem *
create_modem (MMPlugin *self,
              const gchar *sysfs_path,
              const gchar **drivers,
              guint16 vendor,
              guint16 product,
              GList *probes,
              GError **error)
{
    if (mm_port_probe_list_has_qmi_port (probes)) {
        mm_dbg ("QMI-powered Gobi modem found...");
        return MM_BASE_MODEM (mm_broadband_modem_qmi_new (sysfs_path,
                                                          drivers,
                                                          mm_plugin_get_name (self),
                                                          vendor,
                                                          product));
    }

    return MM_BASE_MODEM (mm_broadband_modem_gobi_new (sysfs_path,
                                                       drivers,
                                                       mm_plugin_get_name (self),
                                                       vendor,
                                                       product));
}

/*****************************************************************************/

G_MODULE_EXPORT MMPlugin *
mm_plugin_create (void)
{
    static const gchar *subsystems[] = { "tty", "net", "usb", NULL };
    static const gchar *drivers[] = { "qcserial", NULL };

    return MM_PLUGIN (
        g_object_new (MM_TYPE_PLUGIN_GOBI,
                      MM_PLUGIN_NAME,               "Gobi",
                      MM_PLUGIN_ALLOWED_SUBSYSTEMS, subsystems,
                      MM_PLUGIN_ALLOWED_DRIVERS,    drivers,
                      MM_PLUGIN_ALLOWED_AT,         TRUE,
                      MM_PLUGIN_ALLOWED_QCDM,       TRUE,
                      NULL));
}

static void
mm_plugin_gobi_init (MMPluginGobi *self)
{
}

static void
mm_plugin_gobi_class_init (MMPluginGobiClass *klass)
{
    MMPluginClass *plugin_class = MM_PLUGIN_CLASS (klass);

    plugin_class->create_modem = create_modem;
}