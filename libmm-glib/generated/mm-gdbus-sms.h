/*
 * Generated by gdbus-codegen 2.36.3. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __MM_GDBUS_SMS_H__
#define __MM_GDBUS_SMS_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.freedesktop.ModemManager1.Sms */

#define MM_GDBUS_TYPE_SMS (mm_gdbus_sms_get_type ())
#define MM_GDBUS_SMS(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), MM_GDBUS_TYPE_SMS, MmGdbusSms))
#define MM_GDBUS_IS_SMS(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), MM_GDBUS_TYPE_SMS))
#define MM_GDBUS_SMS_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), MM_GDBUS_TYPE_SMS, MmGdbusSmsIface))

struct _MmGdbusSms;
typedef struct _MmGdbusSms MmGdbusSms;
typedef struct _MmGdbusSmsIface MmGdbusSmsIface;

struct _MmGdbusSmsIface
{
  GTypeInterface parent_iface;


  gboolean (*handle_send) (
    MmGdbusSms *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_store) (
    MmGdbusSms *object,
    GDBusMethodInvocation *invocation,
    guint arg_storage);

  gint  (*get_class) (MmGdbusSms *object);

  GVariant * (*get_data) (MmGdbusSms *object);

  gboolean  (*get_delivery_report_request) (MmGdbusSms *object);

  guint  (*get_delivery_state) (MmGdbusSms *object);

  const gchar * (*get_discharge_timestamp) (MmGdbusSms *object);

  guint  (*get_message_reference) (MmGdbusSms *object);

  const gchar * (*get_number) (MmGdbusSms *object);

  guint  (*get_pdu_type) (MmGdbusSms *object);

  const gchar * (*get_smsc) (MmGdbusSms *object);

  guint  (*get_state) (MmGdbusSms *object);

  guint  (*get_storage) (MmGdbusSms *object);

  const gchar * (*get_text) (MmGdbusSms *object);

  const gchar * (*get_timestamp) (MmGdbusSms *object);

  GVariant * (*get_validity) (MmGdbusSms *object);

};

GType mm_gdbus_sms_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *mm_gdbus_sms_interface_info (void);
guint mm_gdbus_sms_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void mm_gdbus_sms_complete_send (
    MmGdbusSms *object,
    GDBusMethodInvocation *invocation);

void mm_gdbus_sms_complete_store (
    MmGdbusSms *object,
    GDBusMethodInvocation *invocation);



/* D-Bus method calls: */
void mm_gdbus_sms_call_send (
    MmGdbusSms *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean mm_gdbus_sms_call_send_finish (
    MmGdbusSms *proxy,
    GAsyncResult *res,
    GError **error);

gboolean mm_gdbus_sms_call_send_sync (
    MmGdbusSms *proxy,
    GCancellable *cancellable,
    GError **error);

void mm_gdbus_sms_call_store (
    MmGdbusSms *proxy,
    guint arg_storage,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean mm_gdbus_sms_call_store_finish (
    MmGdbusSms *proxy,
    GAsyncResult *res,
    GError **error);

gboolean mm_gdbus_sms_call_store_sync (
    MmGdbusSms *proxy,
    guint arg_storage,
    GCancellable *cancellable,
    GError **error);



/* D-Bus property accessors: */
guint mm_gdbus_sms_get_state (MmGdbusSms *object);
void mm_gdbus_sms_set_state (MmGdbusSms *object, guint value);

guint mm_gdbus_sms_get_pdu_type (MmGdbusSms *object);
void mm_gdbus_sms_set_pdu_type (MmGdbusSms *object, guint value);

const gchar *mm_gdbus_sms_get_number (MmGdbusSms *object);
gchar *mm_gdbus_sms_dup_number (MmGdbusSms *object);
void mm_gdbus_sms_set_number (MmGdbusSms *object, const gchar *value);

const gchar *mm_gdbus_sms_get_text (MmGdbusSms *object);
gchar *mm_gdbus_sms_dup_text (MmGdbusSms *object);
void mm_gdbus_sms_set_text (MmGdbusSms *object, const gchar *value);

GVariant *mm_gdbus_sms_get_data (MmGdbusSms *object);
GVariant *mm_gdbus_sms_dup_data (MmGdbusSms *object);
void mm_gdbus_sms_set_data (MmGdbusSms *object, GVariant *value);

const gchar *mm_gdbus_sms_get_smsc (MmGdbusSms *object);
gchar *mm_gdbus_sms_dup_smsc (MmGdbusSms *object);
void mm_gdbus_sms_set_smsc (MmGdbusSms *object, const gchar *value);

GVariant *mm_gdbus_sms_get_validity (MmGdbusSms *object);
GVariant *mm_gdbus_sms_dup_validity (MmGdbusSms *object);
void mm_gdbus_sms_set_validity (MmGdbusSms *object, GVariant *value);

gint mm_gdbus_sms_get_class (MmGdbusSms *object);
void mm_gdbus_sms_set_class (MmGdbusSms *object, gint value);

gboolean mm_gdbus_sms_get_delivery_report_request (MmGdbusSms *object);
void mm_gdbus_sms_set_delivery_report_request (MmGdbusSms *object, gboolean value);

guint mm_gdbus_sms_get_message_reference (MmGdbusSms *object);
void mm_gdbus_sms_set_message_reference (MmGdbusSms *object, guint value);

const gchar *mm_gdbus_sms_get_timestamp (MmGdbusSms *object);
gchar *mm_gdbus_sms_dup_timestamp (MmGdbusSms *object);
void mm_gdbus_sms_set_timestamp (MmGdbusSms *object, const gchar *value);

const gchar *mm_gdbus_sms_get_discharge_timestamp (MmGdbusSms *object);
gchar *mm_gdbus_sms_dup_discharge_timestamp (MmGdbusSms *object);
void mm_gdbus_sms_set_discharge_timestamp (MmGdbusSms *object, const gchar *value);

guint mm_gdbus_sms_get_delivery_state (MmGdbusSms *object);
void mm_gdbus_sms_set_delivery_state (MmGdbusSms *object, guint value);

guint mm_gdbus_sms_get_storage (MmGdbusSms *object);
void mm_gdbus_sms_set_storage (MmGdbusSms *object, guint value);


/* ---- */

#define MM_GDBUS_TYPE_SMS_PROXY (mm_gdbus_sms_proxy_get_type ())
#define MM_GDBUS_SMS_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), MM_GDBUS_TYPE_SMS_PROXY, MmGdbusSmsProxy))
#define MM_GDBUS_SMS_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), MM_GDBUS_TYPE_SMS_PROXY, MmGdbusSmsProxyClass))
#define MM_GDBUS_SMS_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MM_GDBUS_TYPE_SMS_PROXY, MmGdbusSmsProxyClass))
#define MM_GDBUS_IS_SMS_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), MM_GDBUS_TYPE_SMS_PROXY))
#define MM_GDBUS_IS_SMS_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), MM_GDBUS_TYPE_SMS_PROXY))

typedef struct _MmGdbusSmsProxy MmGdbusSmsProxy;
typedef struct _MmGdbusSmsProxyClass MmGdbusSmsProxyClass;
typedef struct _MmGdbusSmsProxyPrivate MmGdbusSmsProxyPrivate;

struct _MmGdbusSmsProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  MmGdbusSmsProxyPrivate *priv;
};

struct _MmGdbusSmsProxyClass
{
  GDBusProxyClass parent_class;
};

GType mm_gdbus_sms_proxy_get_type (void) G_GNUC_CONST;

void mm_gdbus_sms_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
MmGdbusSms *mm_gdbus_sms_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
MmGdbusSms *mm_gdbus_sms_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void mm_gdbus_sms_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
MmGdbusSms *mm_gdbus_sms_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
MmGdbusSms *mm_gdbus_sms_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define MM_GDBUS_TYPE_SMS_SKELETON (mm_gdbus_sms_skeleton_get_type ())
#define MM_GDBUS_SMS_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), MM_GDBUS_TYPE_SMS_SKELETON, MmGdbusSmsSkeleton))
#define MM_GDBUS_SMS_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), MM_GDBUS_TYPE_SMS_SKELETON, MmGdbusSmsSkeletonClass))
#define MM_GDBUS_SMS_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MM_GDBUS_TYPE_SMS_SKELETON, MmGdbusSmsSkeletonClass))
#define MM_GDBUS_IS_SMS_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), MM_GDBUS_TYPE_SMS_SKELETON))
#define MM_GDBUS_IS_SMS_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), MM_GDBUS_TYPE_SMS_SKELETON))

typedef struct _MmGdbusSmsSkeleton MmGdbusSmsSkeleton;
typedef struct _MmGdbusSmsSkeletonClass MmGdbusSmsSkeletonClass;
typedef struct _MmGdbusSmsSkeletonPrivate MmGdbusSmsSkeletonPrivate;

struct _MmGdbusSmsSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  MmGdbusSmsSkeletonPrivate *priv;
};

struct _MmGdbusSmsSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType mm_gdbus_sms_skeleton_get_type (void) G_GNUC_CONST;

MmGdbusSms *mm_gdbus_sms_skeleton_new (void);


G_END_DECLS

#endif /* __MM_GDBUS_SMS_H__ */
