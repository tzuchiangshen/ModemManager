/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * libmm -- Access modem status & information from glib applications
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2012 Google, Inc.
 */

#ifndef _MM_MODEM_FIRMWARE_H_
#define _MM_MODEM_FIRMWARE_H_

#include <ModemManager.h>

#include "mm-gdbus-modem.h"
#include "mm-firmware-properties.h"

G_BEGIN_DECLS

#define MM_TYPE_MODEM_FIRMWARE            (mm_modem_firmware_get_type ())
#define MM_MODEM_FIRMWARE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), MM_TYPE_MODEM_FIRMWARE, MMModemFirmware))
#define MM_MODEM_FIRMWARE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), MM_TYPE_MODEM_FIRMWARE, MMModemFirmwareClass))
#define MM_IS_MODEM_FIRMWARE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MM_TYPE_MODEM_FIRMWARE))
#define MM_IS_MODEM_FIRMWARE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((obj), MM_TYPE_MODEM_FIRMWARE))
#define MM_MODEM_FIRMWARE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), MM_TYPE_MODEM_FIRMWARE, MMModemFirmwareClass))

typedef struct _MMModemFirmware MMModemFirmware;
typedef struct _MMModemFirmwareClass MMModemFirmwareClass;

/**
 * MMModemFirmware:
 *
 * The #MMModemFirmware structure contains private data and should only be accessed
 * using the provided API.
 */
struct _MMModemFirmware {
    /*< private >*/
    MmGdbusModemFirmwareProxy parent;
    gpointer unused;
};

struct _MMModemFirmwareClass {
    /*< private >*/
    MmGdbusModemFirmwareProxyClass parent;
};

GType mm_modem_firmware_get_type (void);

const gchar *mm_modem_firmware_get_path (MMModemFirmware *self);
gchar       *mm_modem_firmware_dup_path (MMModemFirmware *self);

void     mm_modem_firmware_list        (MMModemFirmware *self,
                                        GCancellable *cancellable,
                                        GAsyncReadyCallback callback,
                                        gpointer user_data);
gboolean mm_modem_firmware_list_finish (MMModemFirmware *self,
                                        GAsyncResult *res,
                                        MMFirmwareProperties **selected,
                                        GList **installed,
                                        GError **error);
gboolean mm_modem_firmware_list_sync   (MMModemFirmware *self,
                                        MMFirmwareProperties **selected,
                                        GList **installed,
                                        GCancellable *cancellable,
                                        GError **error);

void     mm_modem_firmware_select        (MMModemFirmware *self,
                                          const gchar *name,
                                          GCancellable *cancellable,
                                          GAsyncReadyCallback callback,
                                          gpointer user_data);
gboolean mm_modem_firmware_select_finish (MMModemFirmware *self,
                                          GAsyncResult *res,
                                          GError **error);
gboolean mm_modem_firmware_select_sync   (MMModemFirmware *self,
                                          const gchar *name,
                                          GCancellable *cancellable,
                                          GError **error);

G_END_DECLS

#endif /* _MM_MODEM_FIRMWARE_H_ */
