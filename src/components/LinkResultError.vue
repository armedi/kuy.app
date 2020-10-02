<template>
  <div class="w-full max-w-6xl mx-auto">
    <div class="text-white font-light text-center mb-8">
      {{ error }}
    </div>
    <div class="text-center">
      <span
        class="tracking-wide text-gray-100 cursor-pointer border-b border-gray-100 border-dotted"
        @click="$emit('reset')"
      >
        Try again
      </span>
    </div>
  </div>
</template>

<script lang="ts">
import { computed, defineComponent, toRefs, toRef, PropType } from "vue";

export default defineComponent({
  name: "LinkResultError",
  props: {
    error: String
  }
});
</script>
