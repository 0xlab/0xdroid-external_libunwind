LOCAL_PATH := $(call my-dir)

commonCflags	:= -DHAVE_CONFIG_H -DUNW_REMOTE_ONLY

commonIncludes	:= \
	$(LOCAL_PATH)/include \
	$(LOCAL_PATH)/src \
	$(KERNEL_HEADERS)

commonSrcFiles	:= \
	src/mi/init.c \
	src/mi/flush_cache.c \
	src/mi/mempool.c \
	src/mi/strerror.c \
	src/mi/Gdyn-extract.c \
	src/mi/Gdyn-remote.c \
	src/mi/Gfind_dynamic_proc_info.c \
	src/mi/Gget_accessors.c \
	src/mi/Gget_proc_info_by_ip.c \
	src/mi/Gget_proc_name.c \
	src/mi/Gput_dynamic_unwind_info.c \
	src/mi/Gdestroy_addr_space.c \
	src/mi/Gget_reg.c \
	src/mi/Gset_reg.c \
	src/mi/Gget_fpreg.c \
	src/mi/Gset_fpreg.c \
	src/mi/Gset_caching_policy.c \
	src/os-linux.c \
	src/dwarf/global.c \
	src/dwarf/Gexpr.c \
	src/dwarf/Gfde.c \
	src/dwarf/Gparser.c \
	src/dwarf/Gstep.c \
	src/dwarf/Gfind_proc_info-lsb.c \
	src/ptrace/_UPT_elf.c \
	src/ptrace/_UPT_accessors.c \
	src/ptrace/_UPT_access_fpreg.c \
	src/ptrace/_UPT_access_mem.c \
	src/ptrace/_UPT_access_reg.c \
	src/ptrace/_UPT_create.c \
	src/ptrace/_UPT_destroy.c \
	src/ptrace/_UPT_find_proc_info.c \
	src/ptrace/_UPT_get_dyn_info_list_addr.c \
	src/ptrace/_UPT_put_unwind_info.c \
	src/ptrace/_UPT_get_proc_name.c \
	src/ptrace/_UPT_reg_offset.c \
	src/ptrace/_UPT_resume.c

ifeq ($(TARGET_ARCH),arm)
Cflags := $(commonCflags)

Includes := $(commonIncludes) \
	$(LOCAL_PATH)/include/tdep-arm

SrcFiles := $(commonSrcFiles) \
	src/arm/is_fpreg.c \
	src/arm/regname.c \
	src/arm/Gcreate_addr_space.c \
	src/arm/Gget_proc_info.c \
	src/arm/Gget_save_loc.c \
	src/arm/Gglobal.c \
	src/arm/Ginit.c \
	src/arm/Ginit_local.c \
	src/arm/Ginit_remote.c \
	src/arm/Gis_signal_frame.c \
	src/arm/Gregs.c \
	src/arm/Gresume.c \
	src/arm/Gstep.c \
	src/arm/Gex_tables.c
endif # arm

# build static libraries
include $(CLEAR_VARS)
LOCAL_CFLAGS += $(Cflags)
LOCAL_C_INCLUDES := $(Includes)
LOCAL_SRC_FILES	:= $(SrcFiles)
LOCAL_SHARED_LIBRARIES := libc
LOCAL_MODULE := libunwind
LOCAL_MODULE_TAGS := optional
include $(BUILD_STATIC_LIBRARY)
